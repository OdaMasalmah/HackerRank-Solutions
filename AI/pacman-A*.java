import java.util.*;

public class Solution {

    static class Node implements Comparable<Node>{
        int x, y, cost, h;
        Node parent;
        Node(int x, int y, int cost, int h, Node parent) {
            this.x = x;
            this.y = y;
            this.parent = parent;
            this.cost = cost;
            this.h = h;
        }
        @Override
        public String toString() {
            return x + " " + y;
        }

        @Override
        public int compareTo(Node t) {
            return h - t.h;
        }
    }
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int pacmanX = in.nextInt();
        int pacmanY = in.nextInt();
        int goalX = in.nextInt();
        int goalY = in.nextInt();
        int R = in.nextInt();
        int C = in.nextInt();
        
        String [] grid = new String[R];
        
        for (int i = 0; i < R; i++) {
            grid[i] = in.next();
        }
        
        boolean [][] vis = new boolean[R][C];
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                vis[i][j] = false;
            }
        }
        
        // x, y
        // up x- 1, y
        // left x, y- 1
        // right x, y+ 1
        // down x+ 1, y
        int dx[] = {-1, 0, 0, 1};
        int dy[] = {0, -1, 1, 0};
        
        PriorityQueue<Node> queue = new PriorityQueue<>();
        // start state 
        queue.add(new Node(pacmanX, pacmanY, 0, 0, null));
        vis[pacmanX][pacmanY] = true;
        Node refGoal = null;
        
        while ( queue.size() > 0 ) {
            Node current = queue.poll();
            if (current.x == goalX && current.y == goalY) {
                refGoal = current;
                break;
            }
            for (int i = 0; i < 4; i++) {
                int newX = current.x + dx[i];
                int newY = current.y + dy[i];
                if (newX < 0 || newX >= R) continue;
                if (newY < 0 || newY >= C) continue;
                if (grid[newX].charAt(newY)== '%') continue;
                if (vis[newX][newY]) continue;
                vis[newX][newY] = true;
                int cost = current.cost + 1 + get_H(newX, newY, goalX, goalY);
                queue.add(new Node(newX, newY, current.cost+ 1, cost, current));
            }
        }
        System.out.println(refGoal.cost);
        Stack<Node> rev = new Stack<>();
        while (refGoal != null) {
            rev.push(refGoal);
            refGoal = refGoal.parent;
        }
        
        while (rev.size() > 0) 
            System.out.println(rev.pop());
    }
    
    static int get_H(int newX, int newY, int goalX, int goalY) {
        return Math.abs(newX - goalX) + Math.abs(newY - goalY);
    }
}
