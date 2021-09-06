#include <iostream>
#include <cstdlib>
#include<cmath>
#include<ctime>
#include "F:\New folder\collage\FCI-CB\DS & Algo\weeks\week 2\04-Stack-Array-Based.cpp"
using namespace std;

class kotchena
{
private:

const int N = 8;
const int M = 4;
const int X = 4;
int counter=0;

public:

    stack1 a,b,c,d;
    stack1 grid[4]={a,b,c,d};


//This function prints the grid
void print_grid() {
	cout << "\n";
	cout << "  ";
    for (int i = 0; i < M; cout << "   ", i++);
    cout << "  \n";
    for (int i = 0; i < N; i++) {
        cout << "| ";
        cout << grid[0].arr[i] << " |   | " << grid[1].arr[i] << " |   | "  << grid[2].arr[i] << " |   | "
        << grid[3].arr[i] << " | " ;
        cout << " \n";
        cout << "| ";
        for (int i = 0; i < M; cout << "  |   | ", i++);
        cout << "  \n";
    }
    for (int i = 0; i < M; cout << " ----   ", i++);
    cout << "\n";
}

//This function checks if the game has a win state or not
bool check_win() {
    check();
    if( check()==4 ){return true;}
    return false;
}

int check(){
    for(int i=0 ; i<M ; i++){
        for (int j = 0; j < N-3; j++){   

            if( grid[i].arr[j]==4   && grid[i].arr[j+1]==3 && 
                grid[i].arr[j+2]==2 && grid[i].arr[j+3]==1 ){
                counter++;

                for(int p=0 ; p<4 ; p++){
                    grid[i].pop();
                }

                for(int j=grid[i].n ; j<N ; j++){
                    grid[i].arr[j]=0;}
            }
            
            }}
    return counter;
}

//This function checks if given position is valid or not
bool check_valid_column(int i, int j,int k) {
    bool valid = 0<i && i<=M && 0<j && j<=M && 0<k && k<=N
                && grid[j-1].top()-grid[i-1].arr[k-1]==1 || grid[j-1].top()==INT_MAX;
    return valid;
}

//This function clears the game structures
void grid_clear() { 
    for (int i =0 ; i<M ; i++){
        for (int j =0 ; j<N ; j++){
            grid[i].arr[j]=0;
        } 
        grid[i].n=0;
    }
    /*stack1 a,b,c,d,e;
    grid[0]=a;
    grid[1]=b;
    grid[2]=c;
    grid[3]=d;
    grid[4]=e;*/
}

//move 
void set_cell(int i,int j , int k){
    stack1 v;
    while ( grid[i-1].n>k-1)
    {   
        int value=grid[i-1].top();
        grid[i-1].pop();
        v.push(value);
    }
    while (v.n)
    {
        int value=v.top();
        v.pop();
        grid[j-1].push(value);
    }
    for(int j=grid[i-1].n ; j<N ; j++){
        grid[i-1].arr[j]=0;}
    for(int l=grid[j-1].n ; l<N ; l++){
        grid[j-1].arr[l]=0;}
}

//This function generates numbers
void generate_number() {

    srand( (unsigned)time( NULL ) );

    for(int i =0 ; i<N/2 ;i++ ){
        int f = rand() % X +1;
        while ((grid[0].countNumber(f)+grid[1].countNumber(f)+
                grid[2].countNumber(f)+grid[3].countNumber(f))>=4){
            f = rand() % X +1;
        }
        grid[0].push(f);
    }

    for(int i =0 ; i<N/2 ;i++ ){
        int f = rand() % X +1;
        while ((grid[0].countNumber(f)+grid[1].countNumber(f)+
                grid[2].countNumber(f)+grid[3].countNumber(f))>=4){
            f = rand() % X +1;
        }
        grid[1].push(f);
    }

    for(int i =0 ; i<N/2 ;i++ ){
        int f = rand() % X +1;
        while ((grid[0].countNumber(f)+grid[1].countNumber(f)+
                grid[2].countNumber(f)+grid[3].countNumber(f))>=4){
            f = rand() % X +1;
        }
        grid[2].push(f);
    }

    for(int i =0 ; i<N/2 ;i++ ){
        int f = rand() % X +1;
        while ((grid[0].countNumber(f)+grid[1].countNumber(f)+
                grid[2].countNumber(f)+grid[3].countNumber(f))>=4){
            f = rand() % X +1;
        }
        grid[3].push(f);
    }

}

//1=a , 2=b ,  3=c , 4=d , 5=e
bool check_full(int i){
    if(grid[i-1].arr[N-1]!=0){
        return true;}
    else{
    return false;}
}

//This function reads a valid position input
void read_input(int &i , int &j , int &k ) {
    cout << "Enter the column index: ";
    cin >> i >> j >> k;    //|| check_full(j)
    while (!check_valid_column(i,j,k) ) {
        cout << "Enter a valid column index: ";
        cin >> i >> j >> k;
    }
}

//MAIN FUNCTION
void play_game() {
    cout << "solitaire game!\n";
    cout << "Welcome...\n";
    cout << "============================\n";
    while (true) {
        //Prints the grid
        print_grid();
        //Read an input from the player
        int i,j,k;
		read_input(i,j,k);
        //Set the input position with the mark
        set_cell(i, j,k);
        cout<<"your counter = "<<counter<<endl;
        //Check if the state of the grid has a win state
        if (check_win()) {
            //Prints the grid
            print_grid();
            //Announcement of the final statement
            cout << "Congrats, you won!\n";
            break;
        }
        //Check if the state of the grid has a tie state
        /*if (check_tie()) {
            //Prints the grid
            print_grid();
            //Announcement of the final statement
            cout << "Woah! That's a tie!\n";
            break;
        }*/
    }
}
    
};

int main() {
    while (true) {
        kotchena b;
    	b.grid_clear();
        b.generate_number();
    	b.play_game();
    	char c;
    	cout << "Play Again [Y/N] ";
    	cin >> c;
    	if (c != 'y' && c != 'Y')
    		break;
    }
}
