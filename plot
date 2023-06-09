import matplotlib.pyplot as plt 
import numpy as np
import argparse 
parser =argparse.ArgumentParser()
parser.add_argument ('filename')
parser.add_argument ('pdf_filename')
args=parser.parse_args()
data=np.loadtxt(args.filename)
x=data[:,0]
p=data[:,1]
v=data[:,2]
mm=max(max(p),max(v))
#plt.plot(x,v,':ko')
plt.plot(x,v,':k_')
width=0.2
d=np.arange(len(x))
ax=plt.gca()
#ax.bar(x[0]+d-width ,p,width,color='salmon')
ax.bar(x[0]+d-width ,p,width,color='#ff0000')
ax.bar(x[0]+d,v,width,color='royalblue')
plt.xscale("linear")
plt.yscale("linear")
plt.grid(True,'minor')
plt.grid(True,which='major',linestyle='-')
plt.xlabel('$x$')
plt.ylabel('$w(x)$')
plt.savefig(args.pdf_filename, format='pdf')
plt.axis([-0.1,x[len(x)-1]+width+0.1,-0.01,mm+0.01])
plt.show()

