class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> unique;
        
        for (string email : emails) {
            // Split into local and domain
            int atPos = email.find('@');
            string local = email.substr(0, atPos);
            string domain = email.substr(atPos); // includes '@'
            
            // Handle '+': ignore everything after first '+'
            int plusPos = local.find('+');
            if (plusPos != string::npos) {
                local = local.substr(0, plusPos);
            }
            
            // Remove all '.' from local
            local.erase(remove(local.begin(), local.end(), '.'), local.end());
            
            // Combine normalized local and domain
            unique.insert(local + domain);
        }
        
        return unique.size();
    }
};
