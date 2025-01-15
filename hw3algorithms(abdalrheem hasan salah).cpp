

#include <iostream>


    int Dynamic_Programming(int p[], int n,int m[6][6],int split[6][6]) {
     
       

        for (int i = 1; i <= n; i++)

            m[i][i] = 0;

        for (int d = 2; d <= n; d++) { //d=length of subchain

            for (int i = 1; i < n - d + 1; i++) {//i=start of subchain

                int j = i + d - 1;//j=end of subchain

                m[i][j] = 2147483647;

                for (int k = i; k < j; k++) {

                    int cost = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];

                    if (cost < m[i][j])

                        m[i][j] = cost;

                    split[i][j] = k;
                }
            }
        }

        return m[0][5];

       
    }


    int main() {
        
        int p[] = { 30, 35, 15, 5, 10, 20, 25 }; 
        int n = 6;

        int m[6][6];
        int split[6][6];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                m[i][j] = 0;
                split[i][j] = 0;
            }
        }
 
        std::cout<<Dynamic_Programming(p, n,m,split)<<std::endl;

        std::cout << "Best Table:" << std::endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i > j) {
                    std::cout << "-";
                }
                else
                {
                    std::cout << m[i][j] << " ";

                }

            }
            std::cout << std::endl;
        }
        std::cout << "Split Table:" << std::endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i > j) {
                    std::cout << "-";
                }
                else
                {
                    std::cout << split[i][j] << " ";

                }

            }
            std::cout << std::endl;
        }

        return 0;
    

	
}

