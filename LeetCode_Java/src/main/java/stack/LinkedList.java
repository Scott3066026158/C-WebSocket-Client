package stack;
import java.util.LinkedList;
// 双向链表
public class LinkedList<E> {
	
	// 链表头结点
	public Node<E> head = null;
	// 链表尾结点
	public Node<E> tail = null;
	
	// 链表节点结构
	public class Node<E>{
		// 指向上一个节点
		public Node<E> prve;
		// 指向下一个节点
		public Node<E> next;
		// 节点数据
		public E data;
	}
	
	// 添加一个节点(添加到链表末端)
	public boolean add()
	{
		return false;
	}
	
	// 删除一个指定位置的节点
	public boolean remove()
	{
		return false;
	}
	
	
}
