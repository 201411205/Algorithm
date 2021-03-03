package BaekJoon.BackTracking;

import java.io.FileInputStream;
import java.util.Scanner;

import static Util.Constants.INPUT;

// 1���� N���� �ڿ��� �߿��� �ߺ� ���� M���� �� ����
// �� ������ ���������̾�� �Ѵ�.
public class n��m2_15650 {
    static int MAX = 9;
    static int N, M;
    static int[] arr;
    static boolean[] check;
    public static void main(String[] args) throws Exception{
        System.setIn(new FileInputStream(INPUT));
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        M = sc.nextInt();
        arr = new int[M];
        check = new boolean[N];
        dfs(0, 0); // �������� ������ �ϱ� ���� ���� ������ ����� ���� �ε����� ���ڷ� �޾ƿ�
    }

    public static void dfs(int k, int ix) {
        if(k == M) {
            StringBuilder sb = new StringBuilder();
            for(int i = 0; i < M; i++) {
                sb.append(arr[i] + 1).append(" ");
            }
            System.out.println(sb.toString());
            return;
        }
        for(int i = ix; i < N; i++) { // �޾ƿ� �ε��� ���ں��� N���� Ž���ϵ��� �Ͽ� ������������ �ϵ��� ��
            if(!check[i]) {
                check[i] = true;
                arr[k] = i;
                dfs(k + 1, i);
                check[i] = false;
            }
        }
    }
}
