

flips <- sample(c(0,1), size=5, replace=TRUE, prob=c(0.1, 0.9))
print(flips)


d2<-sample(1:6, 10000, replace = T) + sample(1:6, 10000, replace = T)
a<-table(d2)
barplot(a)

