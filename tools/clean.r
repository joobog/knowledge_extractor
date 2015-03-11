# filter data.

d = read.csv("input.original.csv", sep = ";", header=T)

dim(d)

# without datasieving
m1 = subset(d, d[,4] == 4 & d[,3] == 0 )
dim(m1)

# with datasieving

Om1 = subset(d, d[,4] == 1 & d[,3] == 1 )

dim(Om1)

Om4 = subset(d, d[,4] == 4  & d[,3] == 1)
dim(Om4)

Om100 = subset(d, d[,4] == 100 & d[,3] == 1 )
dim(Om100)

dFiltered <- rbind(m1, Om1, Om4, Om100) 
dFiltered<- dFiltered[ order(dFiltered$Data.in.Byte, dFiltered$Gap.in.Byte, dFiltered$Datasieving.1.on, dFiltered$Buffer.in.MByte), ]

library(plyr)

fillLevel <- function(x, y) x / (x + y) * 100
dFiltered <- ddply(dFiltered, .(Data.in.Byte, Gap.in.Byte, Datasieving.1.on, Buffer.in.MByte), transform, fill_level=fillLevel(Data.in.Byte, Gap.in.Byte))

dim(dFiltered)

write.csv(file="dtreeOut.csv", x=dFiltered, )

averages <- ddply(dFiltered, .(Data.in.Byte, Gap.in.Byte, Datasieving.1.on, Buffer.in.MByte), summarize, fill_level = max( fill_level) , mean_value = mean(Performance.in.MByte.s) , min_value = min(Performance.in.MByte.s) , max_value = max(Performance.in.MByte.s) )

write.csv(file="dtreeAveragesClean.csv", x=averages )

