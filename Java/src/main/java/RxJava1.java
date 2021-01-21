import java.util.concurrent.TimeUnit;

public class RxJava1 {

    // �ܺο� ������ �޴� �񵿱� ó�� ����
    private enum State {
        ADD, MULTIPLY
    }

    private static State calcMethod; // �ܺκ���

    public static void main(String[] args) throws Exception {
        // �ʱ⿡ ��� ����� ���ϱ�� ����
        calcMethod = State.ADD;

        Flowable<Long> flowable =
                // 300�и��ʸ��� 0���� �����ϴ� ���� �񵿱�� �����ϴ� Flowable�� interval�� ����
                Flowable.interval(300L, TimeUnit.MILLISECONDS)
                        // 7�Ǳ��� ����
                        .take(7)
                        // scan�� ����� �����ϰ� �����͸� �޾� ����Ҷ����� ����
                        .scan((sum, data) -> { // sum�� ���������� �����, data�� Flowable���� ���� ���� ������
                            if(calcMethod == State.ADD) { // �ܺκ����� ���� ��� ����� �ٸ��� �� => ���� �ؼ��� �ȵ�`
                                return sum + data;
                            } else {
                                return sum * data;
                            }
                        });
        // �����ϰ� ���� �����͸� ���
        flowable.subscribe(data -> System.out.println("data=" + data));

        // ��� ��ٷȴٰ� ��� ����� �������� ����
        Thread.sleep(1000);
        System.out.println("��� ��� ����");
        calcMethod = State.MULTIPLY; // 1000�и��ʸ� ��� �� �ܺ� ���� ���� ����(��������)

        // ��� ���
        Thread.sleep(2000);
    }

//    ��°��
//    data=0
//    data=1
//    data=3
//    ��� ��� ����
//    data=9
//    data=36
//    data=180
//    data=1080
}
