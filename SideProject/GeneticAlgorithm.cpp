//Genetic ALgorithm
/*
It is a method for solving both constrained and unconstrained optimization problems that is based on natural selection,
the process that drives biological evolution. The genetic algorithm repeatedly modifies a population of individual solutions.
*/
#include<bits/stdc++.h>
using namespace std;
struct Solution{
    double rank,x,y,z;
    void fitness(){
        double ans=(6*x+-y+ pow(z,200))-25;//This is the function to be optimized
        rank = (ans==0) ? 9999 : abs(1/ans);//Ranking the solution
    }
};
int main()
{
    //Intial Random Solutions:
    random_device device;
    uniform_real_distribution<double> unif(-100.0,100.0);
    vector<Solution> solutions;

    const int NUM=100000;
    for(int i=0;i<NUM;i++){//Generating 100000 random solutions
        solutions.push_back(Solution{
            0,unif(device),
            unif(device),
            unif(device)
        });
    }
    int a = 100;//Number of iterations
    while(a>0){
        //Writing it to a file
        cout<<"Iteration "<<100-a+1<<endl;
        ofstream file;
        file.open("GeneticAlgorithm.txt",ios::app);
        file<<100-a+1<<endl;
        for_each(solutions.begin(),solutions.begin()+10,[&](const Solution& s){
            file<<fixed
            <<static_cast<int>(s.rank)<<" "
            << s.x <<" "<<s.y<<" "<<s.z
            <<endl;
        });
        file.close();
        //Run for the fitness function for each solution
        for(auto& s:solutions){
            s.fitness();
        }
        //Sort the solutions based on their rank
        sort(solutions.begin(),solutions.end(),[](const Solution& a,const Solution& b){
            return a.rank>b.rank;
        });
        //Print the best solution
        cout<<"Best Solution: "<<endl;
        for_each(solutions.begin(),solutions.begin()+10,[](const Solution& s){
            cout<<fixed
            <<"Rank "<<static_cast<int>(s.rank)
            << "\n x:" << s.x <<"y:"<<s.y<<"z:"<<s.z
            <<endl;
        });

        //Take top Solutions and generate new solutions
        const int SAMPLE_SIZE=1000;
        vector<Solution> sample;
        copy(solutions.begin(),solutions.begin()+SAMPLE_SIZE,back_inserter(sample));
        solutions.clear();

        //Mutate the solutions
        uniform_real_distribution<double> m(0.99,1.01);
        for_each(sample.begin(),sample.end(),[&](Solution& s){
            s.x*=m(device);
            s.y*=m(device);
            s.z*=m(device);
        });

        //Cross over the solutions
        uniform_int_distribution<int> cross(0,SAMPLE_SIZE-1);
        for(int i=0;i<NUM;i++){
            solutions.push_back(Solution{
                0,
                sample[cross(device)].x,
                sample[cross(device)].y,
                sample[cross(device)].z
            });
        }
        sample.clear();
	    a-=1;
    }
    return 0;
}