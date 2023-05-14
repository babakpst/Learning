def main():

   dict_bob = {1:"a", 2:"b", 3:"c", 4: "d", 5:"e"}
   print(dict_bob)

   dict2={}
   delete=[]

   for ke, item in dict_bob.items():
     print("key: {}, item: {} ".format(ke, item))
     dict2[ke*10] = item
     delete.append(ke)

   for ke, item in dict2.items():
     print("key: {}, item: {} ".format(ke, item))
     dict_bob[ke]=item

   for key in delete: del dict_bob[key]

   print(22222)
   for ke, item in dict_bob.items():
     print("key: {}, item: {} ".format(ke, item))
     #dict_bob.pop(ke)

   #dict_bob[111] = dict_bob.pop(1)
   #print(dict_bob)

if __name__=="__main__":
  main()
