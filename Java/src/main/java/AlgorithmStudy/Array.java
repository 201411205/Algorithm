package AlgorithmStudy;

import java.util.ArrayList;
import java.util.Arrays;

public class Array {
    public static void main(String[] args) {
        String[] strings = {"Apple", "Kiwi", "Orange", "Banana", "Watermelon", "Cherry"};

        /** �迭 => ArrayList **/
        ArrayList<String> arr = new ArrayList<>(Arrays.asList(strings));

        /** ArrayList => �迭 **/
        strings = arr.toArray(new String[arr.size()]);

        /** �迭 �� ���� �ʱ�ȭ **/
        Integer[] integers = new Integer[10];
        Arrays.fill(integers, 10);
        System.out.println(Arrays.toString(integers));
    }
}
