INF = int(1e18)
def KM(costMatrix: List[List[int]]) -> Tuple[int, Tuple[List[int], List[int]]]:
    """KM算法求带权二分图的最大权匹配

    Args
    ----------
    costMatrix (List[List[int]]):
        二分图的权值矩阵,不存在的边应初始化为`-INF`

    Returns
    ----------
    Tuple[int, Tuple[List[int], List[int]]]:
        `最大权匹配值, 匹配对的行索引、列索引`

    Examples
    ----------
    >>> costMatrix = [[1, 2, 3], [2, 4, 6], [3, 6, 9]]
    >>> maxSum, (rows, cols) = KuhnMunkres(costMatrix)
    >>> maxSum
    14
    >>> rows cols
    [0, 1, 2] [0, 1, 2]
    >>> sum(costMatrix[i][j] for i, j in zip(rows, cols))
    14
    """
    max_ = max(len(costMatrix), len(costMatrix[0]))
    _match = [-1] * max_  # 记录每个女生匹配到的男生 如果没有则为-1
    _graph = costMatrix  # 记录每个男生和每个女生之间的`好感度`
    _visitedBoy = set()  # 记录每一轮匹配匹配过的男生
    _visitedGirl = set()  # 记录每一轮匹配匹配过的女生
    _expBoy = [max(row) for row in costMatrix]  # 每个男生的期望值
    _expGirl = [0] * max_  # 每个女生的期望值，为0表示只要有一个男生就可以
    _slack = []  # 记录每个女生如果能被男生倾心最少还需要多少期望值
    _pre = []
    _row = len(costMatrix)
    _col = len(costMatrix[0])

    def dfs(boy: int) -> int:
        _visitedBoy.add(boy)
        for girl in range(_col):
            if girl in _visitedGirl:
                continue
            delta = _expBoy[boy] + _expGirl[girl] - _graph[boy][girl]
            # 符合要求
            if delta == 0:
                _visitedGirl.add(girl)
                _pre[girl + _row] = boy
                if _match[girl] == -1:
                    return girl + _row
                _pre[_match[girl]] = girl + _row
                nextRes = dfs(_match[girl])  # 找到增广
                if nextRes > 0:
                    return nextRes
            # 女生要得到男生的倾心 还需多少期望值
            elif _slack[boy] > delta:
                _slack[boy] = delta

        return -1

    for boy in range(_row):
        _visitedBoy.clear()
        _visitedGirl.clear()
        _slack = [INF] * _col
        _pre = [-1] * (_row + _col)
        visited = False
        cand = -1
        # 记录每轮匹配中男生女生是否被尝试匹配过
        while True:
            if not visited:
                cand = dfs(boy)
                visited = True
            else:
                for r in range(_row):
                    if _slack[r] == 0:
                        _slack[r] = INF
                        cand = dfs(r)
                        if cand > 0:
                            break

            if cand > 0:
                tmp = cand
                while tmp > 0:
                    _match[tmp - _row] = _pre[tmp]
                    tmp = _pre[_pre[tmp]]
                break
            else:
                # 如果不能找到 就降低期望值
                # 最小可降低的期望值
                delta = INF
                for c in range(_row):
                    if c in _visitedBoy and _slack[c] < delta:
                        delta = _slack[c]
                for r in range(_row):
                    if r in _visitedBoy:
                        # 所有访问过的男生降低期望值
                        _expBoy[r] -= delta
                        _slack[r] -= delta
                for c in range(_col):
                    if c in _visitedGirl:
                        # 所有访问过的女生增加期望值
                        _expGirl[c] += delta

    # 匹配完成 求出所有配对的好感度的和
    res, rows, cols = 0, [], []
    for girl, boy in enumerate(_match):
        if boy != -1:
            res += _graph[boy][girl]
            rows.append(boy)
            cols.append(girl)
    return res, (rows, cols)

