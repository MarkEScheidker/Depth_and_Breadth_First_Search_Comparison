#include<iostream>
#include<list>
#include<fstream>

int count;
std::ofstream outfile;

class Vertex   //vertex class, contains name of vertex, and a list of vertices it's connected to
{
	public:
		Vertex(char name)
		{
			this->name = name;
		}
		char name;
		int value = 0;
		std::list<Vertex*> arr;
};

class Graph  //list of all vertices
{
	public:
		
	std::list<Vertex*> arr;
};

void arrange_and_print(Graph* graph)  //arrange the values coming from the 
{

	for(int i = 1; i<=10; i++)
	{
		for(Vertex *adjvertex: graph->arr)   //for every item in graph array
		{	
			if(adjvertex->value == i)        //if the vertex's value == i
			{
				std::cout<<adjvertex->name<<" ";  //print and store the vertex's name
				outfile<<adjvertex->name<<" ";
			}
		}
	}
	std::cout<<std::endl;     //new line
	outfile<<std::endl;
	
	for(Vertex *adjvertex: graph->arr)   //reset values for the vertices
	{	
		adjvertex->value = 0;
	}
}

void bfs(Vertex* vertex) 
{
	count++;   //increment count
	vertex->value = count;     //current vertex's value is count
	std::list<Vertex*> list;   //create a list
	list.push_back(vertex);    //push the vertex to the list
	
	while(!list.empty())       //while there are items in the list
	{
		for(Vertex *adjvertex: list.front()->arr)    //for every adjacent vertex
		{
			if(adjvertex->value == 0)            //if the adjacent vertex hasn't been visited
			{		
				count++;                     //add 1 to count
				adjvertex->value = count;       //set adjacent vertex's value to count
				list.push_back(adjvertex);
			}
		}
		list.pop_front();        //pop vertex at the front of the list
	}	
}

void BFS(Graph* graph)
{
	count = 0;                         //reset count to 0
	for(Vertex *vertex: graph->arr)    //for each vertex in the graph
	{
		if(vertex->value == 0)         //if the vertex is zero (uninitialized), then run bfs(vertex)
		{
			bfs(vertex);
		}
	}
}

void dfs(Vertex* vertex)
{
	count++;                       //increment count
	vertex->value = count;         //set vertex's value to count
	for(Vertex *adjvertex: vertex->arr)   //for every adjacent vertex
	{
		if(adjvertex->value == 0)         //if the adjacent vertex hasn't been visited,
		{
			dfs(adjvertex);            //recursively run dfs on adjacent vertex
		}
	}
}

void DFS(Graph* graph)
{
	count = 0;                   //reset count to zero
	for(Vertex *vertex: graph->arr)     //for every vertex in the grapg
	{
		if(vertex->value == 0)      //if the vertex's value is zero (uninitialized), then run dfs(vertex)
		{
			dfs(vertex);
			count;
		}
	}
}

int main()
{
	outfile.open("output.txt");   //create and open file
	
	Vertex* a = new Vertex('a');   //declare all vertices once at the beginning
	Vertex* b = new Vertex('b');
	Vertex* c = new Vertex('c');
	Vertex* d = new Vertex('d');
	Vertex* e = new Vertex('e');
	Vertex* f = new Vertex('f');
	Vertex* g = new Vertex('g');
	Vertex* h = new Vertex('h');
	Vertex* i = new Vertex('i');
	Vertex* j = new Vertex('j');
	
	a->arr = {c,d,e};  //load graph connections for first graph
	b->arr = {e,f};
	c->arr = {a,d,f};
	d->arr = {a,c};
	e->arr = {a,b,f};
	f->arr = {b,c,e};
	g->arr = {h,j};
	h->arr = {g,i};
	i->arr = {h,j};
	j->arr = {g,i};
	
	Graph* graph = new Graph;          //declare graph
	graph->arr = {a,b,c,d,e,f,g,h,i,j};  //laod vertices into graph	
	
	DFS(graph);                           //run depth first search

	arrange_and_print(graph);
	
	BFS(graph);	    //run the same graph with breadth first search
	
	arrange_and_print(graph);	
//------------------------------------------------------------------------------------------	
	
	a->arr = {b,e};             //redeclare the connections of each vertex
	b->arr = {a,c,f};
	c->arr = {b,d,g};
	d->arr = {c};
	e->arr = {a};
	f->arr = {b};
	g->arr = {c};
	
	graph->arr = {a,b,c,d,e,f,g};  //store the new vertecies in the same graph
	DFS(graph);                                      //do the rest exactly like last graph

	arrange_and_print(graph);
	
	BFS(graph);	
	
	arrange_and_print(graph);
//----------------------------------------------------------------------------	

	a->arr = {b,c};     //redeclare vertex connections
	b->arr = {a,d};
	c->arr = {a,e,f};
	d->arr = {b,g};
	e->arr = {c,h};
	f->arr = {c,h};
	g->arr = {d};
	h->arr = {e,f};
	i->arr = {j};
	j->arr = {i};
	
	graph->arr = {a,b,c,d,e,f,g,h,i,j};   //store in new graph
	DFS(graph);							//do the same thing as first and second graph traversal

	arrange_and_print(graph);
	
	BFS(graph);	
	
	arrange_and_print(graph);
//------------------------------------------------------------------------------------

	a->arr = {c};      //same as 1,2, and 3
	b->arr = {c};
	c->arr = {a,b,g};
	d->arr = {e,f};
	e->arr = {d,g,h};
	f->arr = {d,i,j};
	g->arr = {c,e};
	h->arr = {e};
	i->arr = {f,j};
	j->arr = {f,i};
	
	graph->arr = {a,b,c,d,e,f,g,h,i,j};
	DFS(graph);

	arrange_and_print(graph);
	
	BFS(graph);	
	
	arrange_and_print(graph);

	return 0;
}
