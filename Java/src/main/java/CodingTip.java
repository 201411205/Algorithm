import java.io.*;

import static Util.Constants.INPUT;

public class CodingTip {

    public static void main(String[] args) throws Exception{
        base();
        stringOneWordChange();
    }

    // �ڹ� �ڵ��׽�Ʈ �⺻ �ʼ����� �ڵ�
    static void base() throws Exception{
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
    static void stringOneWordChange() {
        String str = "String";
        System.out.println(str);
        StringBuilder sb = new StringBuilder(str);
        sb.setCharAt(0, 'G');
        System.out.println(sb.toString());
    }
}
