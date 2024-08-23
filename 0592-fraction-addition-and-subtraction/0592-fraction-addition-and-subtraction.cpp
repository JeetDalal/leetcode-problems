class Solution {
public:
    // Function to calculate GCD of two numbers
    static int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    // Function to calculate LCM of two numbers
    static int lcm(int a, int b) {
        return (a / gcd(a, b)) * b;
    }

    // Function to calculate LCM of an array of numbers
    int lcmOfArray(const vector<int>& arr) {
        return accumulate(arr.begin(), arr.end(), 1, lcm);
    }

    string fractionAddition(string exp) {
        vector<int> denomVals;
        vector<int> numerVals;
        int numeratorTotal = 0;

        int sign = 1; // To handle positive or negative signs
        int numerator = 0;
        int denominator = 0;

        // Parsing the expression to extract numerators and denominators
        for (int i = 0; i < exp.size();) {
            if (exp[i] == '+' || exp[i] == '-') {
                sign = (exp[i] == '-') ? -1 : 1;
                i++;
            }
            
            // Extract numerator
            numerator = 0;
            while (i < exp.size() && isdigit(exp[i])) {
                numerator = numerator * 10 + (exp[i] - '0');
                i++;
            }
            numerator *= sign; // Apply the sign

            // Skip the '/'
            i++;

            // Extract denominator
            denominator = 0;
            while (i < exp.size() && isdigit(exp[i])) {
                denominator = denominator * 10 + (exp[i] - '0');
                i++;
            }

            numerVals.push_back(numerator);
            denomVals.push_back(denominator);
        }

        // Calculate the LCM of all denominators
        int commonDenominator = lcmOfArray(denomVals);

        // Sum up all numerators after converting to the common denominator
        for (int i = 0; i < numerVals.size(); i++) {
            numeratorTotal += numerVals[i] * (commonDenominator / denomVals[i]);
        }

        // Simplify the resulting fraction
        int commonGCD = gcd(abs(numeratorTotal), commonDenominator);
        numeratorTotal /= commonGCD;
        commonDenominator /= commonGCD;

        // Construct the result as a string
        string result = to_string(numeratorTotal) + "/" + to_string(commonDenominator);
        return result;
    }
};