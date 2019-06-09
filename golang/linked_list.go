package data_structures

import "fmt"

type node struct {
	data interface{}
	next *node
}
type llist struct {
	head *node
	tail *node
	size int
}

func appendToLList(list *llist, data interface{}) {
	node := &node{data: data, next: nil}
	if list.head == nil {
		list.head = node
	} else {
		tmp := list.head
		for tmp.next != nil {
			tmp = tmp.next
		}
		tmp.next = node
	}
	list.size++
}

func popFromLList(list *llist) {
	if list.size > 1 {
		tmp := list.head
		for tmp.next.next != nil {
			tmp = tmp.next
		}
		tmp.next = nil
	} else if list.size == 1 {
		list.head = nil
	}
	list.size--
}

func printLList(list llist) {
	tmp := list.head
	for tmp != nil {
		fmt.Print(fmt.Sprint(tmp.data) + " ")
		tmp = tmp.next
	}
	fmt.Println()
}
