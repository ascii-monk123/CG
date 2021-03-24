class Node:
    def __init__(self,data):
        self.data = data
        self.next = None 
class Solution: 
    def insert(self,head,data):
            p = Node(data)           
            if head==None:
                head=p
            elif head.next==None:
                head.next=p
            else:
                start=head
                while(start.next!=None):
                    start=start.next
                start.next=p
            return head  
    def display(self,head):
        current = head
        while current:
            print(current.data,end=' ')
            current = current.next

    def removeDuplicates(self,head):
        dupArr=[]
        cur,prev=head,head
        if cur:
            dupArr.append(cur)
            cur=cur.next
        while cur:
            if cur.data not in dupArr:
                dupArr.append(cur.data)
                cur=cur.next
                prev=prev.next
            else:
                prev.next=cur.next
                cur=cur.next
        return head
                

mylist= Solution()
T=int(input())
head=None
for i in range(T):
    data=int(input())
    head=mylist.insert(head,data)    
head=mylist.removeDuplicates(head)
mylist.display(head); 

'''
-- select h.hacker_id,h.name,s.submission_id,s.score,c.difficulty_level,d.score from hackers as h inner join submissions as s on h.hacker_id=s.hacker_id 
-- inner join challenges as c on s.challenge_id=c.challenge_id
-- inner join difficulty as d on c.difficulty_level=d.difficulty_level

-- LIMIT 5
-- ;

'''

'''

SELECT CO.CONT,AVG(CO.POP) FROM(SELECT CT.CONTINENT AS CONT,C.POPULATION AS POP FROM COUNTRY AS CT INNER JOIN CITY AS C ON CT.CODE=C.COUNTRYCODE) AS CO GROUP BY CO.CONT;

'''