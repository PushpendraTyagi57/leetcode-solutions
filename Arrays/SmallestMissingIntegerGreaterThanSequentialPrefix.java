import java.util.*;

class SmallestMissingIntegerGreaterThanSequentialPrefix {
    public int missingInteger(int[] nums) {
        int currSum = nums[0];
        int i = 1;
        for (; i < nums.length; i++) {
            if (nums[i] == nums[i - 1] + 1) {
                currSum += nums[i];
            }
            else break;
        }
        HashSet<Integer> st = new HashSet<>();
        for (int num : nums) st.add(num);
        while (st.contains(currSum)) currSum++;
        return currSum;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = sc.nextInt();
        }
        SmallestMissingIntegerGreaterThanSequentialPrefix obj = new SmallestMissingIntegerGreaterThanSequentialPrefix();
        int ans = obj.missingInteger(nums);
        System.out.println(ans);
    }
}