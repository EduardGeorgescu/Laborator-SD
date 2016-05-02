#include <iostream>
#include <vector>
#include "Graph.h"
#include "BinaryTree.h"

using namespace std;

int main()
{
    Tree t;
    int n=0,i,x;

    //Adaugarea elementelor in arbore
    cin>>n;
    for (i=0;i<n;i++)
        cin>>x, t.insert(x);
    //Parcurgerile arborelui
    t.inorder();
    t.preorder();
    //Cautarea unei valori din arbore
    t.find(1);
    t.find(7);

    //Graf
    int j,k,m;
    cin>>n;
    Graph g(n);

    //Adaugarea muchiilor grafului neorientat
    cin>>m;
    for (i=1; i<=m; i++)
    {
        cin>>j>>k;
        g.addEdge(j,k);
        g.addEdge(k,j);
    }
	
	//Parcurgerile arborelui
    cout << "BFS: \n";
    g.BFS(0);

    cout << "DFS: \n";
    g.DFS(0);

    return 0;
}