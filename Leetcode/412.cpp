class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> vec;
        for(int i=1; i <= n; i++){
            string temp="";
            if(i % 3 == 0){
                temp += "Fizz";
            }
            else if(i % 5 != 0){
                temp = to_string(i);
            }
            if(i % 5 == 0){
                temp += "Buzz";
            }
            vec.push_back(temp);
        }
        return vec;
    }
};
