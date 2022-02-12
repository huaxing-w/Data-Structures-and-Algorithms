#include<iostream>
#include<vector>

using namespace std;

const int MAX = 10001;

int nodeNumInStack; // the number of node in the stack
int sccNum;//strongly connected component number
int visitedNum;//current visited number
int dfn[MAX];//first time stamp, first time been visited, "i" value
int low[MAX];//earliest time stamp the node can be backing tracked, "j" value
bool inStack[MAX];//check if the current node in the stack or not
int stack[MAX];//create a stack
int Belong[MAX];//which scc the current node belongs to
int N;//number of node

vector<int> graph[MAX];//create a graph

void dfs(int i) {
    int j;//the nxt node connecting i, this is just a placeholder
    dfn[i] = low[i] = ++visitedNum;//labeling (i,j) to current node i
    inStack[i] = true;//label current node in stack
    stack[++nodeNumInStack] = i;// press i into stack
    for (int k = 0; k < graph[i].size(); k++) {
        j = graph[i][k];
        /*
         * if the nex node has not been visited, run dfs on nxt node
         */
        if (!dfn[j]) {
            dfs(j);
            if (low[j] < low[i]) {
                low[i] = low[j];//update i time backing track stamp if the child has early one
            }
        }
            /*
             * this part is very hard to understand
             * if j is in the stack -> inStack[j]
             * and first visited time stamp of j is less than the current node i backing rack stamp
             * i and j are connected
             * we could update i's backingtrack stamp to j's first visted stamp, as j is first being visited
             *
             */
        else if (inStack[j] && dfn[j] < low[i]) {
            low[i] = dfn[j];
        }
    }
    /*
     * if dfs[i] is same with low[i]
     * i will be the scc root
     */
    if (dfn[i] == low[i]) {
        sccNum += 1;
        cout << "strongly connected component" << sccNum << ": ";
        //pop from stack to find the root
        do {
            j = stack[nodeNumInStack--];
            inStack[j] = false;
            cout << j << " ";
            Belong[j] = sccNum;
        } while (j != i);
        cout << endl;
    }
}

void solve() {
    nodeNumInStack = sccNum = visitedNum = 0;
    memset(dfs, 0, sizeof(dfs));
    for (int i = 0; i <= N; i++) {
        if (!dfn[i]) {
            dfs(i);
        }
    }
}

int main(){
#if 0
    N=6;
    graph[1].push_back(3);
    graph[1].push_back(2);
    graph[2].push_back(4);
    graph[3].push_back(5);
    graph[3].push_back(4);
    graph[4].push_back(1);
    graph[4].push_back(6);
    graph[5].push_back(6);
    
#else
    N=8;
    graph[3].push_back(1);
    graph[1].push_back(2);
    graph[2].push_back(3);
    graph[2].push_back(4);
    graph[5].push_back(2);
    graph[4].push_back(5);
    graph[4].push_back(6);
    graph[5].push_back(6);
    graph[6].push_back(8);
    graph[8].push_back(7);
    graph[7].push_back(6);
#endif
    solve();
    for(int i=0;i<=N;i++){
        cout<<Belong[i]<<" ";
    }
    cout<<endl;
    return 0;
    
}

