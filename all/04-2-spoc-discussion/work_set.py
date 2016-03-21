## work_set complete
import math 

window = 4
mem = [5,4,1]
visit_seq = [3,3,4,2,3,5,3,5,1,4]

def get_mem(num):
	if num not in mem:
		miss = True
		if(len(mem) < window):
			mem.append(num)
		else:
			mem.pop(0)
			mem.append(num)
	else:
		miss = False
		mem.pop(0)
		mem.append(num)
	return miss

for i in visit_seq:
	if get_mem(i):
		print "page_fault happened"
	print "current work_place:", mem