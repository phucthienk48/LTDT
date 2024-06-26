#define oo 99999
#define NO_EDGE 0
#define MAXN 100
#include"stdio.h"
typedef struct{
    int n, w;
    int A[100][100];
}Graph;
void init_Graph(Graph *G, int n){
    int i, j;
    G->n = n;
    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++)
            G->A[i][j] = NO_EDGE;
    }
}

void add_edge(Graph *G, int u, int v, int w){
    G->A[u][v] = w;
    G->A[v][u] = w;
}

int mark[MAXN];
int pi[MAXN];
int p[MAXN];

void MoreDijkstra(Graph *G, int s){
    int u, v, it;
    for(u=1; u<=G->n; u++){
        pi[u]=oo;
        mark[u] = 0;
    }
    pi[s] = 0;
    p[s] = -1;
	for(it=1; it<G->n; it++){
	    int j, min_pi = oo;
	    for(j=1; j<=G->n; j++)
	        if(mark[j]==0 && pi[j]<min_pi){
	            min_pi = pi[j];
	            u = j;  // Di chuy?n d�ng n�y v�o trong v�ng l?p
	        }
	    
	    
	    mark[u] = 1;
	    for(v=1; v<=G->n; v++)
	        if(G->A[u][v] != NO_EDGE && mark[v] == 0)
	            if(pi[u] + G->A[u][v] < pi[v]){
	                pi[v] = pi[u] + G->A[u][v];
	                p[v] = u;
	            }
	        
	    
	}

}


int main(){
    Graph G;
    int n, m, u, v, w, e;
    freopen("dt.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    init_Graph(&G, n);
    for (e = 0; e < m; e++) {
        scanf("%d%d%d", &u, &v, &w);
        add_edge(&G, u, v, w);
    }
    
    MoreDijkstra(&G, 1);
    int i;
    for(i=1; i<=n; i++){
        printf("pi[%d] = %d, p[%d] = %d\n", i, pi[i], i, p[i]);
    }
    
    return 0;
}
