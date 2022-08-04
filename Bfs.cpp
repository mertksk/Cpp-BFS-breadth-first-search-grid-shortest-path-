#include<iostream>
#include<vector>
#include <bits/stdc++.h>

using namespace std;



/*We are able to use any uninformed search algorithm for our solution . I will use BFS (Breath First Search) ,which is widely used in Artificial Intelligence applications and many other fields */


/*Queue Item is to temp row,column and index of Nodes*/
class QItem {
public:
	int row; //hold the row
	int col;  // holds the colum
	bool change;  // if new node created flag becomes 1
	int rowBack;  // holds the row of mother node
	int colBack;		// holds the column of mother node
	QItem(int x, int y,bool c,int rb,int cb)
		: row(x), col(y),change(c),rowBack(rb),colBack(cb)
	{
	}
};


	

/*Function to reverse a Queue by using stack*/
void reverseQueue(queue<QItem> &Queue)
{
    stack<QItem> Stack;
    while (!Queue.empty()) {
        Stack.push(Queue.front());
        Queue.pop();
    }
    while (!Stack.empty()) {
        Queue.push(Stack.top());
        Stack.pop();
    }
}


/*Map Index Takes x and y of the map ,and gives the flattened coordinate for map vector*/
int MapIndex(int point1,int point2,int column){
	
				int index =	point1 + point2*column;
				return index;
}

/*The function that calculates if there is a spesific path for goal point*/
bool FindPath(std::pair<int, int> Start,
              std::pair<int, int> Target,
              const std::vector<int>& Map,
              std::pair<int, int> MapDimensions,
              std::vector<int>& OutPath){
														
							QItem source(Start.second,Start.first , 0 , 0, 0);
							
				
							
							int counter=0;
							bool visited[MapDimensions.first * MapDimensions.second];
							
							
								for(auto itr : Map)	{
									
												
													if ( itr== 0 ){
																
																visited[counter]=true;
														}
														 
														else{
										
															visited[counter]=false;
														} 
														
									
									counter++;
								}
								
																	
													queue<QItem> q; 
													queue<QItem> temp;	//To temp all nodes with their indexes
													
													q.push(source);	
													temp.push(source);
													
													
											  counter=0;
													while (!q.empty()) {
																			
																			QItem p = q.front(); 
																			q.pop();
																	
																			visited[MapIndex(Start.first,Start.second,MapDimensions.first)] = true; 

																			// If the Goal is reached by BFS;
															
																				int rbTemp=-1,cbTemp=-1; //dd
																			
																		  if (p.col == Target.first && p.row== Target.second){      
																		
																										reverseQueue(temp);

																						while (!temp.empty()) {
																							
																										QItem l = temp.front(); 
																										
																								
																										temp.pop();
																										
																										if(l.col == Start.first && l.row == Start.second){
																														continue;
																											}
																										else{
																													if(l.col==Target.first && l.row==Target.second){
																																		
																																						rbTemp= l.rowBack;
																																						cbTemp=l.colBack;
																																						OutPath.push_back(MapIndex(l.col,l.row,MapDimensions.first));

																																						
																																	}
																						
																																	if(l.row==rbTemp && l.col==cbTemp){
																																				 
																																				rbTemp=l.rowBack;
																																				cbTemp=l.colBack;
																																				OutPath.push_back(MapIndex(l.col,l.row,MapDimensions.first));
																																	}													
																												
																											}
																												
																	}
																							reverse(OutPath.begin(), OutPath.end());
																							return true;
																	}
																	
																	
																	
														
																			/*Condition to Move UP*/
																			if (p.row - 1 >= 0 &&	visited[MapIndex(p.col,(p.row - 1),MapDimensions.first)] == false) {
																				q.push(QItem(p.row - 1, p.col,0,p.row, p.col));
																				temp.push(QItem(p.row - 1, p.col,0,p.row, p.col));
																				visited[MapIndex(p.col,(p.row - 1),MapDimensions.first)] = true;

																		
																	 		}
																	 		

																			/*Condition to Move DOWN*/
																			if (p.row + 1 < MapDimensions.second && visited[MapIndex(p.col,(p.row + 1),MapDimensions.first)] == false) {
																			q.push(QItem(p.row + 1, p.col,0,p.row, p.col));
																				temp.push(QItem(p.row + 1, p.col,0,p.row, p.col));
																				visited[MapIndex(p.col,(p.row + 1),MapDimensions.first)] = true;

																	
																			}
																	
																			/*Condition to Move LEFT*/
																			if (p.col - 1 >= 0 &&visited[MapIndex((p.col - 1),p.row,MapDimensions.first)] == false) {
																					q.push(QItem(p.row, p.col - 1, 0,p.row, p.col));
																					temp.push(QItem(p.row, p.col - 1,0,p.row, p.col));
																				visited[MapIndex((p.col - 1),p.row,MapDimensions.first)] = true;

																			
																			}
																	
																			/*Condition to Move RIGHT*/
																			if (p.col + 1 < MapDimensions.first &&	visited[MapIndex((p.col + 1),p.row,MapDimensions.first)] == false) {

															
																						q.push(QItem(p.row, p.col + 1,0,p.row, p.col));
																						temp.push(QItem(p.row, p.col + 1,0,p.row, p.col));
																						visited[MapIndex((p.col + 1),p.row,MapDimensions.first)] = true;

																			}

																		}
		
																		return false; //Returns false if no path is available
																	 }
														
														
														

		  
       	
      //1,0 ->1  0,1 ->9 ,8,2->26


 int main() {
std::vector<int> Map = {1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1};
std::vector<int> OutPath;
cout<<FindPath({0, 0}, {1, 2}, Map, {4, 3}, OutPath);
		for(auto itr:OutPath) cout<<" "<<itr;
	}
