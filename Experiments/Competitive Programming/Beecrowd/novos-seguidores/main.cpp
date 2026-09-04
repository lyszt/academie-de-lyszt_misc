    #include <bits/stdc++.h>
    // problema amaldiçoado
    using namespace std;

    int avg(int n) {
        return ceil(n/30.0);
    }

    int recursive_growth(queue<int>* numbers, int currentF, int neededF, int sum, int neededDays, int stable_days){
        if (currentF >= neededF){
            return neededDays;
        }
        //cout << currentF;
        //cout << currentF << "\n";
        int next = avg(sum);  

        if(next == numbers->front()) {
            stable_days++;
        } else {
            stable_days = 0;
        }
        if(stable_days == 30) {
            // Formula pra retornar o dia depois de 30 dias constantes do mesmo valor
            // Necessário porque não passa o TLE mesmo com queue
            return neededDays + (neededF - currentF + next-1) / next;
        }
        
        sum -= numbers->front();
        sum += next;
        numbers->pop();
        numbers->emplace(next);
        currentF += next;
        

        return recursive_growth(numbers, currentF, neededF, sum, neededDays + 1, stable_days);
    }

    int main()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int currentF;
        int neededF;
        int neededDays = 0;
        queue<int> numbers; 

        cin >> currentF >> neededF;
        int sum = 0;
        for (int i = 0; i < 30; i++)
        {
        int n;
        cin >> n;
        sum += n;
        numbers.emplace(n);
        }
        cout << recursive_growth(&numbers, currentF, neededF, sum, neededDays, 0) << "\n";

        return 0;
    }