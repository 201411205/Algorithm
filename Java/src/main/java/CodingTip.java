import AlgorithmStudy.Array;

import java.io.*;
import java.util.Arrays;

import static Util.Constants.INPUT;

public class CodingTip {

    public static void main(String[] args) throws Exception{
        base();
        stringOneWordChange();
        init2DArrayByUseStream();
        changeStringArrayToIntArrayByUseStream();
    }

    // �ڹ� �ڵ��׽�Ʈ �⺻ �ʼ����� �ڵ�
    private static void base() throws Exception{
        System.setIn(new FileInputStream(INPUT)); // freopen �����ϴ� �Լ�
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();
        final int n = Integer.parseInt(br.readLine());

        // .......... //

        bw.write(sb.toString().trim()); // trim �� ����Ͽ� ������ �� ���� ������
        bw.flush();
        bw.close();
        br.close(); // !!!!! �߿� ���۸���, ������ close �Լ��� �������� �� �ݾ��� �� !!!!!
    }

    // �ڹ� ��Ʈ������ �� ���ڸ� �����ϰ� ������
    private static void stringOneWordChange() {
        String str = "String";
        System.out.println(str);
        StringBuilder sb = new StringBuilder(str);
        sb.setCharAt(0, 'G');
        System.out.println(sb.toString());
    }

    // 2���� �迭 �ʱ�ȭ �� ��� ���
    private static void init2DArrayByUseStream() {
        int MAX = 5;
        int[][] d = new int[MAX][MAX];
        // 2���� �迭 0���� �ʱ�ȭ
        Arrays.stream(d).forEach(it -> Arrays.fill(it, 0));
        // 2���� �迭�� ����Ϸ��� deepToString�� ����ؾ��� *1���� �迭�� �Ϲ� toString
        System.out.print(Arrays.deepToString(d));
    }

    // ��Ʈ�� ���ڿ� �迭�� int�� �迭�� �� ��ȯ�� ��Ʈ���� ����Ͽ� �� �ٷ� �ϴ� ���
    private static void changeStringArrayToIntArrayByUseStream() {
        String[] str = {"111", "123", "777"};
        // mapToInt�� ����Ͽ� int������ �� ��ȯ �׸��� ���� �� ���� �� int �迭�� ����
        int[] arr = Arrays.stream(str).mapToInt(Integer::parseInt).sorted().toArray();
        Arrays.stream(arr).forEach(it -> System.out.print(it + " "));
    }
}
