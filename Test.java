class Node<T>
{
        T val;
        Node prev,next;
        Node(T val)
        {
                this.val=val;
        }
}
class DoubleLinkList<T>
{
        private Node<T> head,tail;
        public int addFront(Node<T> n)
        {
                if(head == null && tail == null)
                        head = tail = n;
                else
                {
                        tail.next = n;
                        tail = n;
                }
                return 0;
        }
        public int addBack(Node<T> n)
        {
                if(tail == null && tail == null)
                        head = tail = n;
                else
                {
                        head.prev = n;
                        head = n;
                }
                return 0;
        }
        public int removeFront()
        {
                /**if(tail == null)
                        throw new Exception(){};
                else**/ if(head == tail)
                        head = tail = null;
                else
                {
                        tail = tail.prev;
                        tail.next = null;
                }
                return 0;
        }
        public int removeBack()
        {
                /**if(head == null)
                        throw new Exception(){};
                else**/ if(head == tail)
                        head = tail = null;
                else
                {
                        head = head.next;
                        head.prev = null;
                }
                return 0;
        }
        public String print()
        {
            String str = new String();
            str = "[";
            Node<T> curr = head;
            do
            {
                str += "\t" + curr.val.toString();
                curr = curr.next;
            }
            while(curr != null);
            str += "]";
            return str;
        }
}
public class Test
{
        public static void main(String a[])
        {
                DoubleLinkList<Integer> list = new DoubleLinkList();
                list.addFront(new Node<Integer>(5));
                list.addFront(new Node<Integer>(4));
                System.out.println(list.print());
        }
}