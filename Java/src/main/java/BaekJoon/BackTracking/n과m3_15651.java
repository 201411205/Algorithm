package BaekJoon.BackTracking;

import java.io.FileInputStream;
import java.util.Scanner;

import static Util.Constants.INPUT;

// 1���� N���� �ڿ��� �߿��� M���� �� ����
// ���� ���� ���� �� ��� �ȴ�.
public class n��m3_15651 {
    static int N, M;
    static int[] arr;
    public static void main(String[] args) throws Exception{
        System.setIn(new FileInputStream(INPUT));
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        M = sc.nextInt();
        arr = new int[M];
        dfs(0);
    }

    public static void dfs(int k) {
        if(k == M) {
            StringBuilder sb = new StringBuilder();
            for(int i = 0; i < M; i++)
                sb.append(arr[i] + 1).append(" ");
            System.out.println(sb.toString());
            return;
        }
        for(int i = 0; i < N; i++) {
            arr[k] = i;
            dfs(k + 1);
        }
    }
}
