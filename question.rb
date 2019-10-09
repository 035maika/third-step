require "numo/narray"

rika=Numo::SFloat[65,80,67,35,58,60,72,75,68,92,36,50,2,58.5,46,42,78,62,84,70]
eigo=Numo::SFloat[44,87,100,63,52,60,58,73,55,86,29,56,89,23,65,84,64,27,86,84]

print"理科の平均:#{rika.mean}\n"
print"理科の標準偏差:#{rika.stddev}\n"
print"理科の合計:#{rika.sum}\n"
print"英語の平均:#{eigo.mean}\n"
print"英語の標準偏差:#{eigo.stddev}\n"
print"英語の合計:#{eigo.sum}\n"

stu = 0
rika.each do |x|
ss = (x - rika.mean) / rika.stddev * 10 + 50
stu=stu+1

print "生徒",stu,":理科の標準偏差",ss,"\n"
end

stu = 0
eigo.each do |x|
ss = (x - eigo.mean) / eigo.stddev * 10 + 50
stu=stu+1

print "生徒",stu,":英語の標準偏差",ss,"\n"
end
print"理科の高い順\n"

sort2 =  rika.sort
20.times do |i|
 puts sort2[i] 
end
print"英語の高い順\n"

sort2 =  eigo.sort
20.times do |i|
 puts sort2[i] 
end
