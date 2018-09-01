hubbledata<- read.table("hubble.dat", header=TRUE)
print(hubbledata)
x<- log10(hubbledata$rvel)
y<- log10(hubbledata$pmag)
# Plot the data
plot(x, y, xlab="rvel", ylab="pmag")
# Use a linear model to perform a simple linear regression
lmfit<- lm(y~x)
cat("fit parameters: ",lmfit$coefficients,"\n")
cat("standard errors: ",sqrt(diag(vcov(lmfit))),"\n")
print(summary(lmfit))
# Plot regression line
abline(lmfit)
# Do the same using the simpler lsfit function
fit<- lsfit(x, y, intercept=TRUE)
print(summary(fit))
abline(fit, col="red")
