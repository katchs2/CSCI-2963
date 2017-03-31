# car_placed_door<-sample(1:3,1000,replace=TRUE)
# car_stopmoviesion_door<-sample(1:3,1000,replace=TRUE)
# sum(car_placed_door==car_stopmoviesion_door)
col_names <- names(topmovies)
topmovies[,col_names] <- lapply(topmovies[,col_names] , factor)
# library(arules)
rules.all <- apriori(topmovies)
rules <- apriori(topmovies, control = list(verbose=F),
                 parameter = list(minlen=2, supp=0.005, conf=0.8))
source("http://bioconductor.org/biocLite.R")
biocLite("Rgraphviz")
rules.sorted <- sort(rules, by="confidence")
inspect(rules.sorted)
# library(arulesViz)
# plot(topmovies.sorted)
# max(topmovies$TotalVote)
# topmovies[topmovies$TotalVote==max(topmovies$TotalVote),]
# topmovies$BushPct = as.numeric(topmovies$BushPct)
# topmovies$KerryPct = as.numeric(topmovies$KerryPct)
# win = topmovies[topmovies$BushPct > topmovies$KerryPct,]

key <- "man"
manMovie = topmovies[grepl(key, topmovies$name),]

key <- "Episode|I"
consecMovie = topmovies[grepl(key, topmovies$name),]
key <- "Star Wars"
starMovie = topmovies[grepl(key, topmovies$name),]