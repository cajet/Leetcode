vector<int> diffWaysToCompute(string input) 
{
    vector<int> result;
    
    for (int k = 0; k < input.size(); k++)
    {
        if (input[k] == '*' || input[k] == '-' || input[k] == '+')
        {
            vector<int> left = diffWaysToCompute(input.substr(0, k));
            vector<int> right = diffWaysToCompute(input.substr(k + 1));
            for (int i = 0; i < left.size(); i++)
            {
                for (int j = 0; j < right.size(); j++)
                {
                    if (input[k] == '*')
                        result.push_back(left[i] * right[j]);
                    else if (input[k] == '-')
                        result.push_back(left[i] - right[j]);
                    else
                      result.push_back(left[i] + right[j]);  
                }
            }
        }
    }
    
    if (result.empty())
        result.push_back((int)atoi(input.c_str()));
    
    return result;
}