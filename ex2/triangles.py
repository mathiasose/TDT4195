import random
from math import sqrt, pow

def line_intersect(v1,v2,v3,v4):
    '''
    judge if line (v1,v2) intersects with line(v3,v4)
    '''
    d = (v4[1]-v3[1]) * (v2[0]-v1[0])-(v4[0]-v3[0])*(v2[1]-v1[1])
    u = (v4[0]-v3[0]) * (v1[1]-v3[1])-(v4[1]-v3[1])*(v1[0]-v3[0])
    v = (v2[0]-v1[0])*(v1[1]-v3[1])-(v2[1]-v1[1])*(v1[0]-v3[0])
    if d<0:
        u,v,d= -u,-v,-d
    return (0<=u<=d) and (0<=v<=d)

def point_in_triangle(A,B,C,P):
    v0 = [C[0]-A[0], C[1]-A[1]]
    v1 = [B[0]-A[0], B[1]-A[1]]
    v2 = [P[0]-A[0], P[1]-A[1]]
    cross = lambda u,v: u[0]*v[1]-u[1]*v[0]
    u = cross(v2,v0)
    v = cross(v1,v2)
    d = cross(v1,v0)
    if d<0:
        u,v,d = -u,-v,-d
    return u>=0 and v>=0 and (u+v) <= d

def tri_intersect(t1, t2):
    '''
    judge if two triangles in a plane intersect 
    '''
    if any([line_intersect(t1[0],t1[1],t2[0],t2[1]), line_intersect(t1[0],t1[1],t2[0],t2[2]), line_intersect(t1[0],t1[1],t2[1],t2[2]),
           line_intersect(t1[0],t1[2],t2[0],t2[1]), line_intersect(t1[0],t1[2],t2[0],t2[2]), line_intersect(t1[0],t1[2],t2[1],t2[2]),
           line_intersect(t1[1],t1[2],t2[0],t2[1]), line_intersect(t1[1],t1[2],t2[0],t2[2]), line_intersect(t1[1],t1[2],t2[1],t2[2])
           ]):
        return True

    if all([point_in_triangle(t1[0],t1[1],t1[2], t2[0]), point_in_triangle(t1[0],t1[1],t1[2], t2[1]), point_in_triangle(t1[0],t1[1],t1[2], t2[2])]):
        return True
    
    if all([point_in_triangle(t2[0],t2[1],t2[2], t1[0]), point_in_triangle(t2[0],t2[1],t2[2], t1[1]), point_in_triangle(t2[0],t2[1],t2[2], t1[2])]):
        return True

    return False

x = lambda: round(random.uniform(-1, 1), 1)

def area(triangle):
    a = sqrt(pow(triangle[1][0] - triangle[0][0], 2) + pow(triangle[1][1] - triangle[0][1], 2))
    b = sqrt(pow(triangle[2][0] - triangle[1][0], 2) + pow(triangle[2][1] - triangle[1][1], 2))
    c = sqrt(pow(triangle[0][0] - triangle[2][0], 2) + pow(triangle[0][1] - triangle[2][1], 2))
    
    p = (a + b + c) / 2
    try:
        return sqrt(p*(p-a)*(p-b)*(p-c))
    except:
        return 0

ts = set()
while len(ts) < 10:
    b = ((x(), x(), 0.0), (x(), x(), 0.0), (x(), x(), 0.0))

    if area(b) < 0.05:
        continue

    if any([tri_intersect(a, b) for a in ts]):
        continue
    
    ts.add(b)

for t in ts:
    for p in t:
        print("{}f, {}f, {}f,".format(*p))
    print()
