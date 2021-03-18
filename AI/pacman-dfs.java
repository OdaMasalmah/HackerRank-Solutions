import java.util.*;

public class Solution {

    static class Node {
        int x, y;
        Node parent;
        Node(int x, int y, Node parent) {
            this.x = x;
            this.y = y;
            this.parent = parent;
        }
        @Override
        public String toString() {
            return x + " " + y;
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
        
        ArrayList<Node> explore = new ArrayList<>();
        Stack<Node> st = new Stack<>();
        // start state 
        st.push(new Node(pacmanX, pacmanY, null));
        vis[pacmanX][pacmanY] = true;
        Node refGoal = null;
        while ( st.size() > 0 ) {
            Node current = st.pop();
            explore.add(current);
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
                st.add(new Node(newX, newY, current));
            }
        }
        System.out.println(explore.size());
        for (Node X: explore) 
            System.out.println(X);
        Stack<Node> rev = new Stack<>();
        while (refGoal != null) {
            rev.push(refGoal);
            refGoal = refGoal.parent;
        }
        System.out.println(rev.size()- 1);
        while (rev.size() > 0) 
            System.out.println(rev.pop());
    }
}
