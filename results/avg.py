names = ["min_max", "print_in_order", "rebalance", "time"]
types = ["AVL", "BST", "BST_degenerate"]

for i in types:
    for j in names:
        file_name = i + '_' + j
        f1 = open(file_name+"1.txt", "r")
        f2 = open(file_name+"2.txt", "r")
        f3 = open(file_name+"3.txt", "r")
        f4 = open(file_name+"4.txt", "r")
        result = open("final_results/"+file_name+".txt", "w")

        line1 = f1.readline()

        while line1:
            line2 = f2.readline()
            line3 = f3.readline()
            line4 = f4.readline()
            avg = int(line1[line1.index(' ')+1:]) + int(line2[line2.index(' ')+1:]) + int(line3[line3.index(' ')+1:]) + int(line4[line4.index(' ')+1:])
            avg = avg/4
            R = line1[:line1.index(' ')] + " " + str(avg)
            result.write(R)
            result.write("\n")
            line1 = f1.readline()