
import java.util.Arrays;
import java.util.Deque;
import java.util.LinkedList;

public class  Solution150{
    public static void main(String[] args) {
        String[] tokens = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
        Solution ss = new Solution();
        System.out.println(ss.evalRPN(tokens));

    }
}

class Solution {
    public int evalRPN(String[] tokens) {
        Deque<Integer> st = new LinkedList<Integer>();
        for (String token : tokens) {
            if (token.equals("+")) {
                int a = st.pop();
                int b = st.pop();
                st.push(a + b);
            }
            else if (token.equals(("-"))) {
                int a = st.pop();
                int b = st.pop();
                st.push(b - a);
            }
            else if (token.equals("*")) {
                int a = st.pop();
                int b = st.pop();
                st.push(a * b);
            }
            else if (token.equals("/")){
                int a = st.pop();
                int b = st.pop();
                st.push(b / a);
            }
            else 
                st.push(Integer.parseInt(token));
        }
        return st.pop();
    }
}