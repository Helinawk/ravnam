import matplotlib.pyplot as plt
import numpy as np
import argparse
parser=argparse.ArgumentParser()
parser.add_argument('filename')
parser.add_argument('pdf_filename')
args=parser.parse_args()
data=np.loadtxt(args.filename)
x=data[:,0]
p=data[:,1]
v=data[:,2]
x2=np.atleast_2d(x).T
x2=np.column_stack((x2,x2))
x2=x2.flatten()
p2=np.atleast_2d(p).T
p2=np.column_stack((p2,p2))
p2=p2.flatten()
v2=np.atleast_2d(v).T
v2=np.column_stack((v2,v2))
v2=v2.flatten()
x2=np.insert(x2,0,0)
p2=np.insert(p2,0,0)
p2=np.insert(p2,0,0)
v2=np.insert(v2,0,0)
v2=np.insert(v2,0,0)
x2=np.append(x2,2*x2[len(x2)-1]-x2[len(x2)-3])
x2=np.append(x2,x2[len(x2)-1])
x2=np.append(x2,2*x2[len(x2)-1]-x2[len(x2)-3])
p2=np.append(p2,1)
p2=np.append(p2,1)
v2=np.append(v2,1)
v2=np.append(v2,1)
plt.plot(x,v,':k')
rr=[]
bb=[]
srr=[]
sbb=[]
for i in range (len(x2)):
    srr.append(plt.plot(x2[i*2:i*2+2],p2[i*2:i*2+2],'-r'))
    plt.setp(srr[i],linewidth=3.0)
    sbb.append(plt.plot(x2[i*2:i*2+2],v2[i*2:i*2+2],'-b'))
    plt.setp(sbb[i],linewidth=3.0)
    rr.append(plt.plot(x2[i*2+1:i*2+3],p2[i*2+1:i*2+3],'--r'))
    plt.setp(rr[i],linewidth=3.0)
    bb.append(plt.plot(x2[i*2+1:i*2+3],v2[i*2+1:i*2+3],'--b'))
    plt.setp(bb[i],linewidth=3.0)
    width=0.2
    d=np.arange(len(x))
    ax=plt.gca()
    ax.bar(x[0]+d+width/2.,p,width,color='salmon')
    ax.bar(x[0]+d-width/2,v,width,color='royalblue')
    plt.xscale("linear")
    plt.yscale("linear")
    plt.grid(True,'minor')
    plt.grid(True, which='major', linestyle='-')
    plt.xlabel('$x$')
    plt.ylabel('$w(x)$')
    plt.savefig(args.pdf_filename, format='pdf')
    plt.axis([-0.1,x2[len(x2)-1]+0.1,-0.01,1.01])
    plt.show()