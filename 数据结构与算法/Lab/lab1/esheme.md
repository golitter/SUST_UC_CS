##   2.1 Storage Scheme

### Cn

 

顺序存储存储多项式结构方便，但是当项的指数幂差别大时，浪费了空间，同时对多项式的增加和删除元素来说，是O（n）级别。链式存储结构采用链表的形式，不会造成空间的浪费，同时还可以多项式的大小不受限制，多项式的增加和删除元素更加方便。

### Zn

Sequential storage is a convenient structure for storing polynomials, but it wastes space when the exponential power of an item varies greatly, and it is at the O(n) level for adding and deleting elements of a polynomial. The chain storage structure uses the form of a chain table, which does not waste space. At the same time, the size of the polynomial can be unlimited. It is more convenient to add and delete elements of the polynomial.





### cn

对链表进行归并排序。用快慢指针将链表分为两部分，直到链表只有一个结点时不再进行划分。之后对两个链表添加头或尾指针，将两个链表联合成一个顺序链表，之后一直重复该步骤。最后返回链表头指针。

### zn

Merge and sort the linked lists. Divide the linked list into two parts with the fast or slow pointer until there is only one node in the linked list. Then add a head or tail pointer to the two linked lists, combine the two linked lists into a sequential linked list, and then repeat this step all the time. Finally, return the chain header pointer.