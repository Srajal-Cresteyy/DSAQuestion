class Solution {
public:
    bool check(int val,int sum,string number){
        if(sum==val and number.size()==0) return true;
        if(number.size()==0 || sum>val) return false;

        string one="";
        while(number.size()){
            one=number.back()+one;
            number.pop_back();
            if(check(val,sum+stoi(one),number))
                return true;
        }

        return false;
    }
    int punishmentNumber(int n) {
        int count=0;
        for(int i=1;i<=n;i++)
            if(check(i,0,to_string(i*i))){
                count+=i*i;
                cout<<i<<endl;
            }
        return count;
    }
};


//A really good problem to understand recursion indeed just take the numbers of different sizes and keep adding them it is kind of dynamic divide and 
//conquer approach 
