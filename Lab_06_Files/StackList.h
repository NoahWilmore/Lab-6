#if !defined STACKLIST_H
#define STACKLIST_H

#include "ListLinked.h"

template < class T >
class StackList
{

   private:
      ListLinked<T>* list;

   public:
      StackList();
      ~StackList();

      bool isEmpty();
      int size();
      void popAll();

      T* pop();
      void push(T* item);
      T* peek();

};

template < class T >
StackList<T>::StackList()
{
   list = new ListLinked<T>();
}

template < class T >
StackList<T>::~StackList()
{
   delete list;
}

template < class T >
bool StackList<T>::isEmpty()
{
   return size() == 0;
}

template < class T >
int StackList<T>::size()
{
   return list->size();
}

template < class T >
T* StackList<T>::peek()
{
   T* item = NULL;
   if (!isEmpty()) 
   {  
      item = list->get(1);
   }
   return item;
}

template < class T >
void StackList<T>::push(T* item)
{
   list->add(1, item);
}

template < class T >
T* StackList<T>::pop()
{
   T* item = NULL;
   if (!isEmpty()) 
   {  
      item = list->get(1);
      list->remove(1);
   }
   return item;
}

template < class T >
void StackList<T>::popAll()
{
   delete list;
   list = new ListLinked<T>();
}

#endif
