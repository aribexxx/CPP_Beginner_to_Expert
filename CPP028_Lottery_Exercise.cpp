/**
 * Author:    Tridib Samanta
 * Created:   27.01.2020
 **/

#include<iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//不理解逻辑


/* Sample Output:
Enter the total number of people : 
10
Enter the total number of prizes : 
5
The winners are : 
8
9
2
4
5

*/
void lottery(int, int);

int main() {

    int total_people,total_winners;
    cout<<"Enter the total number of people : "<<endl;
    cin>>total_people;
    cout<<"Enter the total number of prizes : "<<endl;
    cin>>total_winners;
    lottery(total_people,total_winners);
    return 0;
}

void lottery(int total_balls, int balls_to_draw)
{
    if(total_balls < balls_to_draw) {
        cout<<"Draw not possible";
        return;
    }

    cout<<"The winners are : "<<endl;

    srand(time(NULL));

    int *balls = new int[balls_to_draw];

    for(int i=0;i<balls_to_draw;i++) {
         
        balls[i] = rand() % total_balls + 1;
        for(int j=0;j<i+1;j++) {
            printf("i : %d j : %d\n",i,j);
            printf("balls[i] : %d balls[j] : %d\n",balls[i],balls[j]);
            if(balls[i]==balls[j] && i!=j) {
                i--;
                break;
            }
            else if(j==i)
                cout<<"------------------#"<<j<<" of winner: "<<balls[i]<<endl;
        }
    }

    delete[] balls;
}
