// ADD EID  & add better comments
// prob can just type straight from git hub


#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <iomanip>
#include <fstream>
#include <cmath>

using std::cin;
using std::cout;
using std::string;


using std::make_shared;
using std::shared_ptr;
using std::vector;
using std::endl;


class Matrix{
    private:
   // <magic stuff from you>
        bool initalized_;
        int rows_;
        int columns_;
        vector<vector<double>> m_;
        int iters_;
        double tol_;
        bool flag_;
        double solveTime_;
        int solveIters_;
        double error_;

    public:


        Matrix() //DONE
        { 
            m_ = vector<vector<double>>();
            initalized_ = false;
        }

        Matrix(int rows, int cols)
        {
            rows_ = rows;
            columns_ = cols;
            m_ = vector<vector<double>>();
            initalized_ = true;
            m_.resize(rows_);

            for(int i = 0; i < rows_; i++)
            {
                m_[i].resize(columns_);
                for(int j = 0; j < columns_; j++)
                {
                    m_[i][j] = 0;
                }
            }
            
        }

        vector<double> getRow(int index)
        {
            return m_[index];
        }

        void setRow(int r, vector<double> row)
        {
            m_[r] = row;
        }

        void initIdentity(int n) //DONE
        {
            initalized_ = true;
            rows_ = n;
            columns_ = n;
            m_.resize(rows_);
            
            for(int i = 0; i < rows_; i++)
            {
                m_[i].resize(columns_);
                for(int j = 0; j < columns_; j++)
                {
                    
                    
                    if(j == i)
                    {
                        m_[i][j]= 1;
                    }
                    else
                    {
                        m_[i][j]= 0;
                    }
                    
                }
            }
        }
        

        
        bool isSquare()
        {
            if (!initalized_)
            {
            cout << "[Error]: slow your roll and please initialize matrix first" << endl;
            exit(1);
            }
            return rows_ == columns_;
        }

        void Print(string name) // DONE
        {
            if (!initalized_)
            {
            cout << "[Error]: slow your roll and please initialize matrix first" << endl;
            exit(1);
            }
            double num;
            
            double len = name.size();

            cout<< name << " = ";


            for(int i = 0; i < rows_; i++)
            {
                if(i != 0)
                {
                    for (int l= 0; l< len + 3; l++)
                    {
                        cout << " ";
                    }
                }
                std::cout<< "|";
                for(int j = 0; j < columns_; j++)
                {
                    num = m_[i][j];
                    std::cout << num;
                }
                std::cout << " |" << endl;
            }
            cout << "\n";
        }


        double getVal(int row, int col)
        {
            if (!initalized_)
            {
            cout << "[Error]: slow your roll and please initialize matrix first" << endl;
            exit(1);
            }
            if(row >= rows_ || col >= columns_ || row < 0 || col < 0)
            {
                cout << "[Error]: index not in Matrix" << endl;
                exit(1);
            }
            
            return m_[row][col];
        }

        void setVal(int row, int col, double val)
        {
            if (!initalized_)
            {
            cout << "[Error]: slow your roll and please initialize matrix first" << endl;
            exit(1);
            }
            if(row >= rows_ || col >= columns_ || row < 0 || col < 0)
            {
                cout << "[Error]: index not in Matrix" << endl;
                exit(1);
            }
            
            m_[row][col] = val;
        }

        vector<double> Diagonal()
        {
            if (!initalized_)
            {
            cout << "[Error]: slow your roll and please initialize matrix first" << endl;
            exit(1);
            }
            if(!isSquare())
            {
                cout << "[Error]: matrix is not square. Therefore it does not have a diagonal" << endl;
            }
            vector<double> v = vector<double>();
            v.resize(rows_);
            for(int i = 0; i < rows_; i++)
            {
                v[i] = m_[i][i];
            }
            return v;
        }


        int numRows() // DONE
        {
            if (!initalized_)
            {
            cout << "[Error]: slow your roll and please initialize matrix first" << endl;
            exit(1);
            }
            return rows_;
        }
        int numCols() // DONE
        {
            if (!initalized_)
            {
            cout << "[Error]: slow your roll and please initialize matrix first" << endl;
            exit(1);
            }
            return columns_;
        }


                

        Matrix Multiply(double A)
        {
            if (!initalized_)
            {
            cout << "[Error]: slow your roll and please initialize matrix first" << endl;
            exit(1);
            }

            Matrix temp = Matrix(rows_, columns_);
            double num;
            

            for(int i = 0; i < rows_; i++)
            {
                for (int j = 0; j < columns_; j++)
                {
                    num = m_[i][j] * A;
                    
                    temp.setVal(i,j,num);
                }
            }
            return temp;
        }

        Matrix Multiply(Matrix B)
        {
            if (!initalized_)
            {
            cout << "[Error]: slow your roll and please initialize matrix first" << endl;
            exit(1);
            }
            if (columns_ != B.numRows())
            {
            cout << "[Error]: Matrix multiplication invalid due to format" << endl;
            exit(1);

            }
            double num;


            Matrix temp = Matrix(rows_, B.numCols());
            for(int i = 0; i < temp.numRows(); i++)
            {
                for (int j = 0; j < temp.numCols(); j++)
                {
                    num = 0;
                    for(int l = 0; l< columns_; l++)
                    {
                        
                        num += (m_[i][l] * B.getVal(l,j));
                    }
                    
                    temp.setVal(i,j,num);
                }
            }
            return temp;
            
        }

        Matrix Transpose()
        {
            if (!initalized_)
            {
            cout << "[Error]: slow your roll and please initialize matrix first" << endl;
            exit(1);
            }

            Matrix temp = Matrix(columns_, rows_);
            double num;
            

            for(int i = 0; i < rows_; i++)
            {
                for (int j = 0; j < columns_; j++)
                {
                    num = m_[i][j];
                    
                    temp.setVal(j,i,num);
                }
            }
            return temp;
        }

        void setSolveMaxIters(int iters)
        {
            if (!initalized_)
            {
            cout << "[Error]: slow your roll and please initialize matrix first" << endl;
            exit(1);
            }
            iters_ = iters;
        }

        void setSolveTolerance(double tol)
        {
            if (!initalized_)
            {
            cout << "[Error]: slow your roll and please initialize matrix first" << endl;
            exit(1);
            }
            tol_ = tol;
        }

        int getSolveIters()
        {
            if (!initalized_)
            {
            cout << "[Error]: slow your roll and please initialize matrix first" << endl;
            exit(1);
            }
            return solveIters_;
        }

        void setSolveDebugMode(bool flag)
        {
            if (!initalized_)
            {
            cout << "[Error]: slow your roll and please initialize matrix first" << endl;
            exit(1);
            }
            flag_ = flag;

        }

        double getSolveTime()
        {
            if (!initalized_)
            {
            cout << "[Error]: slow your roll and please initialize matrix first" << endl;
            exit(1);
            }
            return solveTime_;
        }

        void setSolveTime(double solveTime)
        {
            if (!initalized_)
            {
            cout << "[Error]: slow your roll and please initialize matrix first" << endl;
            exit(1);
            }
            solveTime_ = solveTime;
        }

        void setFlag(bool flag)
        {
            if (!initalized_)
            {
            cout << "[Error]: slow your roll and please initialize matrix first" << endl;
            exit(1);
            }
            flag_ = flag;
        }

        bool getFlag()
        {
            if (!initalized_)
            {
            cout << "[Error]: slow your roll and please initialize matrix first" << endl;
            exit(1);
            }
            return flag_;
        }
};




class ProbabilityDistribution
{
    private:
        vector<double> numbers;

    public:
        ProbabilityDistribution(int size)
        {  
            numbers = vector<double>(size, 0);
        }

        vector<double> getVec()
        {
            return numbers;
        }

        void setVec(vector<double> vec)
        {
            numbers = vec;
        }

        float getProb(int index)
        {
            return numbers.at(index);
        }

        void set_random()
        {
            float random;

            for(int i = 0; i < numbers.size(); i++)
            {
                random = rand() % 10;
                numbers[i] = random;
            }
        }

        void normalize()
        {
            float sum = 0;
            for(int i = 0; i < numbers.size(); i++)
            {
                sum+= numbers.at(i);
            }
            if(sum!= 0)
            {
                for(int i = 0; i < numbers.size(); i++)
                {
                    numbers[i] /= sum;
                }
            }
        }

        string as_string()
        {
            string str = "";
            for(int i = 0; i < numbers.size(); i++)
            {
                str = str + std::to_string(i) + ": " + std::to_string(numbers[i]) + "\n"; 
            }

            return str;
        }

        void setProb(int index, float num)
        {
            numbers[index] = num;
        }

        


};

class Page{
    private:
        int linkamount;
        string name;
        vector<shared_ptr<Page>> links;
        shared_ptr<Page> next{nullptr};
        int globalID;
        int totalPages;

    public:
        
        // Page constructor
        Page(string n)
        {
            linkamount = 0;
            links.resize(1);
            name = n;
            
        }

        Page(string n, int id)
        {
            linkamount = 0;
            links.resize(1);
            name = n;
            globalID = id;

            
        }

        Page(string n, int id, int length)
        {
            linkamount = 0;
            links.resize(1);
            name = n;
            globalID = id;
            totalPages = length;

            
        }

        auto global_ID()
        {
            return globalID;
        }

        int link_amount()
        {
            return linkamount;
        }

        void link(){
            cout << "there is none" << "\n";
        };
        auto as_string(){
            return name;
        };

        void add_link(shared_ptr<Page> p)
        {
            // allocating new link into a point
            
            links[linkamount] = p;
            
            linkamount++;
            links.resize(linkamount+1);
        }

        shared_ptr<Page> click(int i)
        {
            return links[i];
        }

        shared_ptr<Page> random_click()
        {
            if(linkamount == 0)
            {
                throw("ERROR: no links. Need to program this CASE. \n");
            }
            // providing a seed value
 //           srand(time(NULL));

            // get a random number within the given number of links
            int random = rand() % linkamount;
            
            return click(random);
        }

        ProbabilityDistribution distribution()
        {
            shared_ptr<Page> page;
            ProbabilityDistribution dist = ProbabilityDistribution(totalPages);
            for(int i =0; i < linkamount; i++)
            {
                page = links[i];
                int pageIndex = page->global_ID();
                dist.setProb(pageIndex,dist.getProb(pageIndex)+1);
            }
            dist.normalize();
            return dist;
        }

};


class Web
{
    private:
        
        int netsize;
        vector<shared_ptr<Page>> pages;
        vector<ProbabilityDistribution> distributions;
        Matrix matrix_form;
        Matrix distributions_matrix;

        int artificialSize;
        




    public:
        Web(int size)
        {
            netsize = size;
            pages.resize(netsize);
            
            for(int i = 0; i < size; i++)
            {
                auto str = std::to_string(i);
                auto name = "Page " + str;
                
                pages[i] = make_shared<Page>(name, i, size);
            }
        }

        Web(int size, int artSize)
        {
            artificialSize = artSize;
            netsize = size;
            pages.resize(artificialSize);
            
            for(int i = 0; i < artificialSize; i++)
            {
                auto str = std::to_string(i);
                auto name = "Page " + str;
                
                pages[i] = make_shared<Page>(name, i, artificialSize);
            }
        }

        

        vector<ProbabilityDistribution> getDistributions()
        {
            return distributions;
        }

        Matrix get_distMatrix()
        {
            return distributions_matrix;
        }

        void setDistributions()
        {
            distributions = vector<ProbabilityDistribution>(netsize, NULL);
            distributions_matrix = Matrix(netsize,netsize);

            shared_ptr<Page> page;

            for(int i = 0; i < netsize; i++)
            {
                page = pages[i];
                distributions[i] = page->distribution();
                distributions_matrix.setRow(i, distributions[i].getVec());

            }
        }

        void setArtificialDistributions()
        {
            distributions = vector<ProbabilityDistribution>(artificialSize, NULL);
            distributions_matrix = Matrix(artificialSize, artificialSize);

            shared_ptr<Page> page;

            for(int i = 0; i < artificialSize; i++)
            {
                page = pages[i];
                distributions[i] = page->distribution();
                distributions_matrix.setRow(i, distributions[i].getVec());

            }
        }

        ProbabilityDistribution globalclick(ProbabilityDistribution currentstate)
        {
            Matrix v = Matrix(1, currentstate.getVec().size());
            
            v.setRow(0, currentstate.getVec());

            ProbabilityDistribution r = ProbabilityDistribution(currentstate.getVec().size());

            for(int i = 0; i < distributions_matrix.numRows(); i++)
            {
                for (int j = 0; j < distributions_matrix.numCols(); j++)
                {
                    if(distributions_matrix.getVal(i,j) != 0)
                    {
                        break;
                    }
                    if(j + 1 == distributions_matrix.numCols())
                    {
                        //Set row to random distribution to simulate picking a random page on the web
                        // This is for case of no outbound links
                        r.set_random();
                        r.normalize();

                        distributions_matrix.setRow(i, r.getVec());

                    }
                }
            }
            
            Matrix temp = v.Multiply(distributions_matrix);

            ProbabilityDistribution k = ProbabilityDistribution(currentstate.getVec().size());
            
            k.setVec(temp.getRow(0));

            return k;
        }
        

        auto fully_connected()
        {
            Matrix m = Matrix(netsize, netsize);
            m.initIdentity(netsize);
            
            int index;

            for(int i = 0; i < netsize; i++)
            {
                
                shared_ptr<Page> p = pages[i];
                for(int j = 0; j<p->link_amount(); j++)
                {
                    index = p->click(j)->global_ID();
                    
                    m.setVal(i,index,1);
                }
            }

            matrix_form = m;
            
            Matrix multiplied = m;

            for(int i = 0; i < netsize; i++)
            {
                multiplied = multiplied.Multiply(m);
            }

            for(int i = 0; i < netsize; i++)
            {
                for(int j = 0; j< netsize; j++)
                {
                    if(multiplied.getVal(i,j) == 0)
                    {
                        return false;
                    }
                }
            }
            return true;

        }

        auto all_pages()
        {
            return pages;
        }

        auto number_of_pages()
        {
            return netsize;
        }


	auto random_page()
        {
             int randNum = rand() % netsize;
             return pages.at(randNum);
        }

        void create_random_links(int avgLinks)
        {
            

            int n = avgLinks * netsize;
 //           srand(time(NULL));

            // get a random number within the given number of links
            int randomX, randomY;
            for(int i = 0; i < n; i++)
            {
                //Pick page from pages vector at random (page1 = rand page)
                randomX = rand() % netsize;

                //Pick second page from pages vector at random (page 2 = rand page)
                randomY = rand() % netsize;
                while (randomX == randomY){
                    randomY = rand() % netsize;
                }
                //Set link from page1 to page2 (page1.addlink(page2))
                auto pageX = pages[randomX];
                auto pageY = pages[randomY];
                pageX->add_link(pageY);
            }
        }

        auto random_walk(shared_ptr<Page> startingPage, int length)
        {
            //Current page set to starting page to track which page we started at
            shared_ptr<Page> currentPage = startingPage;
            for(int i = 0; i < length; i++)
            {
                if(currentPage->link_amount() == 0)
                {
                    return currentPage;
                }
                currentPage = currentPage->random_click();
            }
            return currentPage;
        }

        auto getPage(int n)
        {
            return pages[n];
        }

        void print()
        {
            for(int i = 0; i < netsize; i++)
            {
                cout << pages[i]->as_string() << std::endl;
            }
        }

	int diameter()
	{
		
		auto currentPage = getPage(1);
		auto startPage = getPage(1);
		auto endPage = getPage(2);
		int numSteps = 0;
		int totalSteps;
        int vecPosition = 0;
        vector<int> shortestPath((netsize*netsize) - netsize); 
        int longestPath = 0;

        // 2 forloops to go from any page A to any Page B, while loop runs that specific walk many times to find shortest path.
		for( int i = 0; i < netsize; i++){
			startPage = getPage(i);		
		
			for (int j = 0; j < netsize; j++){
		        totalSteps = 2*netsize;
			    numSteps = 0;
		           	
		        if ( j == i) { j++;}
		        if (j>=netsize) {break;}	
			    endPage = getPage(j);		    

			    for (int w = 0; w < netsize*10; w++){ // similates the walk from page A to page B netsize*10 # of times to find shortest path from A to B
				while (currentPage != endPage){
 	                numSteps++;
                    currentPage = random_walk(currentPage, 1);
				    if (numSteps >= netsize){break;}	
				}
				if (numSteps < totalSteps){
					totalSteps = numSteps;
				}
				numSteps = 0;
				currentPage = startPage;
			    }

			   // cout << "Shortest path from page " << i << " to page " << j << " is " << totalSteps << std::endl; 
               // Can use to see all shortest paths between any 2 pages
                shortestPath[vecPosition] = totalSteps;
                vecPosition++;
			}
			
		}
        // find ths longest path from all the shortest paths
        for (int i = 0; i < shortestPath.size(); i++){ 
            if (shortestPath[i] > longestPath){
                longestPath = shortestPath[i];
            }
        }

        // cout << "Diameter is " << longestPath << endl;
        return longestPath;
	}


};





int main()
{
    srand(time(NULL));
    int netsize = 10;
    int artificialSize = 40;


    //Web internet(netsize);

    Web internet(netsize,artificialSize);

    int avglinks = 5;
    
    internet.create_random_links(avglinks);

    shared_ptr<Page> google;
    shared_ptr<Page> inflation;
    for(int i = netsize; i < artificialSize; i++)
    {
        
        google = internet.getPage(i);
        
        inflation = internet.getPage(artificialSize-1);
        
        google->add_link(inflation);
        
    }

    internet.setArtificialDistributions();
    vector<ProbabilityDistribution> dis = internet.getDistributions();

    Matrix a = internet.get_distMatrix();
    
    ProbabilityDistribution v = ProbabilityDistribution(artificialSize);
    vector<double> vec = vector<double>(artificialSize, 0);
    
    double maxErr = 10;
    
    v.setVec(vec);
    v.set_random();
    v.normalize();
    
    //v.set_random();
    //v.normalize();
    vector<double> vec1,vec2;
    int mag1;
    int mag2;
    int sum;
    int count = 0;
    double error;



    while (maxErr > .00001 || count > 2000) // i added this or statement bc never ending loop was happening sometimes
    {
        maxErr = 0;
        vec1 = v.getVec();

        v = internet.globalclick(v);

        vec2 = v.getVec();
        
        for(int i = 0; i < artificialSize; i++)
        {
            error = abs(vec2[i]- vec1[i]);
            if(error > maxErr)
            {
                maxErr = error;
            }
        }

        count++;
        if (count == 1000){cout << "count > 1000";} 
    }

    
// why is the output the way it is?
    cout << "Artifically inflated\n" << v.as_string() << endl;
     
    cout << "COUNT IS " <<  count << endl;
// Diameter testing ... WORKS 
    /*
    int diam = internet.diameter();
    cout << "The diameter of the internet is " << diam << endl;
    */

    
/*
    vector<int> landing_counts(internet.number_of_pages(),0);
//    for ( auto page : internet.all_pages() ) 
      for ( int run = 1; run < 100; run++)
     {
        auto curPage = internet.random_page();
        for (int iwalk=0; iwalk<=1; iwalk++) {

	    int randomSteps = rand() % 2*avglinks;
            auto endpage = internet.random_walk(curPage, randomSteps);

            
            landing_counts.at(endpage->global_ID())++;
        }
    }

  for (int i = 0; i < landing_counts.size(); i++){

	cout << "Page " << i << " Landed on: "  << landing_counts.at(i) << ", Total Links: " << internet.getPage(i)->link_amount() <<  std::endl;

  }
  */
    // Checking if internet is fully connected
    auto connect = internet.fully_connected();
    if(connect)
    {
        int diam1 = internet.diameter();
        cout << "Fully Connected: Diameter of the Internet is " << diam1 << endl;
    }
    else
    {
        cout << "Multiple Connected Components" << endl;
    }
    

    /* Testing probability distribution
    ProbabilityDistribution prob = ProbabilityDistribution(10);
    prob.set_random();
    prob.normalize();

    string g = prob.as_string();
    cout << g;
    */
   
    return 0;
}
