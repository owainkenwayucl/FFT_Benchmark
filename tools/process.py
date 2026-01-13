# This script processes output.txt to generate a useful CSV table.
# THis script is fragile

filename = "output.txt"

with open(filename, "r") as f:
	while(True):
   		try:
			threads_line = f.readline().strip()
			threads = threads_line.split(": ")[1]
			temp = f.readline()
			temp = f.readline()
			t = []
			for a in range(6):
				line = f.readline()
				t.append(line.split(", ")[2])
			temp = f.readline()
			print(f"{threads}, {t[0]}, {t[1]}, {t[2]}, {t[3]}, {t[4]}, {t[5]}")
		except:
			break
