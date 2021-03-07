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

    // 자바 코딩테스트 기본 필수적인 코드
    private static void base() throws Exception{
        System.setIn(new FileInputStream(INPUT)); // freopen 역할하는 함수
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();
        final int n = Integer.parseInt(br.readLine());

        // .......... //

        bw.write(sb.toString().trim()); // trim 을 사용하여 마지막 빈 줄을 없애줌
        bw.flush();
        bw.close();
        br.close(); // !!!!! 중요 버퍼리더, 라이터 close 함수로 마지막에 꼭 닫아줄 것 !!!!!
    }

    // 자바 스트링에서 한 문자만 변경하고 싶을때
    private static void stringOneWordChange() {
        String str = "String";
        System.out.println(str);
        StringBuilder sb = new StringBuilder(str);
        sb.setCharAt(0, 'G');
        System.out.println(sb.toString());
    }

    // 2차원 배열 초기화 및 출력 방법
    private static void init2DArrayByUseStream() {
        int MAX = 5;
        int[][] d = new int[MAX][MAX];
        // 2차원 배열 0으로 초기화
        Arrays.stream(d).forEach(it -> Arrays.fill(it, 0));
        // 2차원 배열을 출력하려면 deepToString을 사용해야함 *1차원 배열은 일반 toString
        System.out.print(Arrays.deepToString(d));
    }

    // 스트링 문자열 배열을 int형 배열로 형 변환을 스트림을 사용하여 한 줄로 하는 방법
    private static void changeStringArrayToIntArrayByUseStream() {
        String[] str = {"111", "123", "777"};
        // mapToInt를 사용하여 int형으로 형 변환 그리고 사전 순 정렬 후 int 배열로 만듬
        int[] arr = Arrays.stream(str).mapToInt(Integer::parseInt).sorted().toArray();
        Arrays.stream(arr).forEach(it -> System.out.print(it + " "));
    }
}
