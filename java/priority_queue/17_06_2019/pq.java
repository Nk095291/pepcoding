import java.util.*;

public class pq {
    // Q1.print the k largest elements of the array
    public static void klargest(int[] ar, int k) {
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for (int i = 0; i < k; i++)
            pq.add(ar[i]);
        for (int i = k; i < ar.length; i++) {
            if (ar[i] > pq.peek()) {
                pq.remove();
                pq.add(ar[i]);
            }
        }
        for (int x : pq)
            System.out.println(x);
    }

    // Q2.sort the almost sorted array
    public static void almostSortedArray(int ar[], int k) {
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for (int i = 0; i < ar.length; i++) {
            if (i < k) {
                pq.add(ar[i]);
            } else {
                pq.add(ar[i]);
                System.out.print(pq.remove() + " ");
            }
        }
        while (pq.size() > 0)
            System.out.print(pq.remove() + " ");
        System.out.println();

    }

    public static class helper implements Comparable<helper> {
        int value;
        int i;
        int j;

        helper(int value, int i, int j) {
            this.value = value;

            this.i = i;

            this.j = j;
        }

        public int compareTo(helper other) {
            return this.value - other.value;
        }

    };
//Q3. make an sorted array with k sorted arrays
    public static void mergeKsort(ArrayList<ArrayList<Integer>> ar) {
        PriorityQueue<helper> pq = new PriorityQueue<>();
        for (int i = 0; i < ar.size(); i++) {
            pq.add(new helper(ar.get(i).get(0), i, 0));
        }
        while (pq.size() > 0) {
            helper rem = pq.remove();
            System.out.print(rem.value + " ");
            if (rem.j + 1 < ar.get(rem.i).size())
                pq.add(new helper(ar.get(rem.i).get(rem.j + 1), rem.i, rem.j + 1));
        }
        System.out.println();

    }
// Q4. median priority queue
    static class mypq {
        PriorityQueue<Integer> left = new PriorityQueue<>(Collections.reverseOrder());
        PriorityQueue<Integer> right = new PriorityQueue<>();

        public void resize() {
            if (left.size() - right.size() == 2) {
                right.add(left.remove());
            } else if (left.size() - right.size() == -2) {
                left.add(right.remove());
            }

        }

        public void push(int data) {
            if (left.size() != 0 && data < left.peek()) {
                left.add(data);
            } else {
                right.add(data);
            }
            resize();
        }

        public int top() {
            if (left.size() > right.size())
                return left.peek();
            return right.peek();
        }

        public void pop() {
            if (left.size() > right.size()) {
                left.remove();
            } else {
                right.remove();
            }
        }

        public int size() {
            return left.size() + right.size();
        }

    }

    public static void main(String[] argv) {
        // int ar[]={2,8,14,5,6,1,9,4,20,3,11};
        // klargest(ar, 4);
        // int ar[]={20,40,10,30,50,80,60,90,70,120,110,100};
        // almostSortedArray(ar, 2);
        // ArrayList<ArrayList<Integer>> ar = new ArrayList<>();
        // ar.add(new ArrayList<>(Arrays.asList(2,5,9,18)));
        // ar.add(new ArrayList<>(Arrays.asList(3,7,8,15,22)));
        // ar.add(new ArrayList<>(Arrays.asList(0,4,6,12)));
        // ar.add(new ArrayList<>(Arrays.asList(1,10,16,21,28)));
        // mergeKsort(ar);

        mypq pq = new mypq();
        pq.push(10);
        System.out.print(pq.top() + " ");
        pq.push(20);
        System.out.print(pq.top() + " ");
        pq.push(50);
        System.out.print(pq.top() + " ");
        pq.push(30);
        System.out.print(pq.top() + " ");
        pq.push(100);
        System.out.print(pq.top() + " ");
        System.out.println();
        while (pq.size() > 0) {
            System.out.print(pq.top() + " ");
            pq.pop();
        }

    }
}