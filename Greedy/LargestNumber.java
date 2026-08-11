import java.util.*;

class LargestNumber {
    public String largestNumber(int[] nums) {
        Comparator<String> cmp = new Comparator<String>() {
            @Override
            public int compare(String s1, String s2) {
                String num1 = s1 + s2; //303
                String num2 = s2 + s1; //330
                return num2.compareTo(num1);
            }
        };
        List<String> strs = new ArrayList<>();
        for (int num : nums) strs.add(Integer.toString(num));
        Collections.sort(strs, cmp);
        if (strs.get(0).equals("0")) return "0";
        StringBuilder sb = new StringBuilder();
        for (String str : strs) sb.append(str);
        return sb.toString();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = sc.nextInt();
        }
        LargestNumber obj = new LargestNumber();
        String ans = obj.largestNumber(nums);
        System.out.println(ans);
    }
}