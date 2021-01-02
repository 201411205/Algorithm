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
 * �������� ������ N���� �� N���� ū ���� ����� N�� �������� ���ѵڿ� �װ��� 2����� �̸� �迭�� ũ�⸦ �����ؾ� ��
 * �������� ������ 12���̸� 16 * 2 = 32���� ũ�Ⱑ �ʿ�
 * ���� ������ �������� ���� N�� 4�� ���� ũ�⸸ŭ �̸� ���� �� Ʈ���� ������ �Ҵ�
 *
 * 2. ���� ���� ���ϴ� �Լ�
 * ���� ���� �׻� O(logN)�� �ð��� ���� �� ����
 * ���� ���� ���ϴ� �Լ� ���� ��������� �����ϴ� ���� ȿ������
 * ���� ���� ���� �ȿ� �ִ� ��쿡 ���ؼ� �����ָ� ��
 *
 * 3. Ư�� ������ ���� �����ϴ� �Լ�
 * �ش� ���Ҹ� �����ϰ� �ִ� ��� ���� �� ������ �����ϸ� ��
 * �� ���� ���� �ȿ� �ִ� ��쿡 ���ؼ� �����ָ�
 * ��������� �����ϴ� ���� ȿ������
 *
 * ���� ���׸�Ʈ Ʈ�� �˰����� ����ϸ� ���� �� ��� �� ���� ������� ȹ�������� �ӵ��� �������� ��
 *
 * ��ó : https://blog.naver.com/ndb796/221282210534
 *
 */

public class SegmentTree {
    static int NUMBER = 12;
    static int a[] = {1,9,3,8,4,5,5,9,10,3,4,5};
    static int tree[] = new int[4 * NUMBER];
    public static void main(String[] args) {
        init(0, NUMBER - 1, 1);
        System.out.println("0 ���� 12������ ��");
        System.out.println(sum(0, NUMBER - 1, 1, 0, 12));
        System.out.println("3 ���� 8������ ��");
        System.out.println(sum(0, NUMBER - 1, 1, 3, 8));
        System.out.println("�ε��� 5�� ���Ҹ� -5�� ����");
        update(0, NUMBER - 1, 1, 5, -5);
        System.out.println("3 ���� 8������ ��");
        System.out.println(sum(0, NUMBER - 1, 1, 3, 8));
    }

    // ���� �� Ʈ�� ����
    // start ���� �ε���, end �� �ε���
    private static int init(int start, int end, int node) {
        if(start == end) return tree[node] = a[start];
        int mid = (start + end) / 2;
        // ��������� �� �κ��� ���� �� ���� ����
        return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
    }

    // left, right => ���� ���� ���ϰ��� �ϴ� ����
    private static int sum(int start, int end, int node, int left, int right) {
        // ���� �ۿ� �ִ� ���
        if(left > end || right < start) return 0;
        // ���� �ȿ� �ִ� ���
        if(left <= start && end <= right) return tree[node];
        // �׷��� �ʴٸ� �� �κ����� ������ ���� ���ϱ�
        int mid = (start + end) / 2;
        return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
    }

    // index : ���� ���� �����ϰ��� �ϴ� ���
    // dif : ������ �� => �������� �ٲٷ��� ���� ���� => ��ŭ ������ ��
    private static void update(int start, int end, int node, int index, int dif) {
        // ���� �ۿ� �ִ� ���
        if(index < start || index > end) return;
        // ���� �ȿ� ������ �������� �ٸ� ���ҵ� ����
        tree[node] += dif;
        if(start == end) return;
        int mid = (start + end) / 2;
        update(start, mid, node * 2, index, dif);
        update(mid + 1, end, node * 2 + 1, index, dif);
    }
}
