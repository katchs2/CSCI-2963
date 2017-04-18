

coeffs<-sample(-20:20, 3, replace=T)
class(coeffs)
length(coeffs)
names(coeffs)
names(coeffs)<- c("a","b","c")
names(coeffs)
x<-seq(-3,3,length=200)
y<-coeffs[1]*x^2+coeffs[2]*x+coeffs[3]

plot(x,y)

disc<-coeffs[2]^2-4*coeffs[1]*coeffs[3]
disc

######
temp<-c(-16, -2, -3, 21, 28, 36, 50, 47, 35, 24, 14, 1)
sum(temp)
length(temp)
mean(temp)
sort(temp)
median(temp)
sd(temp)
var(temp)
sd(temp)^2
sum((temp-mean(temp)^2) / length(temp)-1) ## checking

min(temp)
max(temp)
summary(temp)
plot(temp)
hist(temp)

count<-0
## for statements in R
for (i in 1:100){
  if (disc < 0){
    count<+ 1
  }
}
print(count)

