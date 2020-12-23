package AlgorithmStudy;

/**
 * ���׸�Ʈ Ʈ��
 * Ư���� ������ ������ ���� ���� ������ �����ϰ� ���� �� �ִ� �ڷᱸ��
 * �ð����⵵ O(logN)
 *
 * 1. ���� �� Ʈ�� ����
 * �ֻ�� ��忡�� ��ü ���Ҹ� ���� ���� ��
 * �ι�°, ����° ������ ���� ������ ������ �ݾ� �����ϸ� �� ������ �յ��� �����ϵ��� ����
 * *** ���� �� Ʈ���� ���ؼ� �ε��� ��ȣ�� 1���� ����
 *      => 1���� ���������ν� 2�� ������ �� ���� �ڽ� ��带 ����Ű�Ƿ� ȿ������ => ���� ¦���� ���� Ȧ���� �������� ����Ű�� ��
 * ���� �� Ʈ���� ��������� �����ϴ� ���� ȿ����
 * �������� ������
 *
 * https://blog.naver.com/ndb796/221282210534
 *
 */

public class SegmentTree {
    static int NUMBER = 12;
    static int a[] = {1,9,3,8,4,5,5,9,10,3,4,5};
    static int tree[] = new int[4 * NUMBER];
    public static void main(String[] args) {
        init(0, NUMBER - 1, 1);
    }

    private static int init(int start, int end, int node) {
        if(start == end) return tree[node] = a[start];
        int mid = (start + end) / 2;
        return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
    }
}
