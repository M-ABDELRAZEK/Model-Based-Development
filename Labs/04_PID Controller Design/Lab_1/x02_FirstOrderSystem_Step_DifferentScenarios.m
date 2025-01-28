K = [1 3 5];
T = [1 3 5];

legendLabels = {};
for i = 1:length(K)
    for j = 1:length(T)
        num = [K(j)];
        den = [T(i) 1];
        G = tf(num, den);
        step(G, 10);
        hold on;
        title("Studying Variation of K and T")
        xlabel("Time");
        ylabel("Output");
        legendLabels{end + 1} = "K = " + num2str(K(i)) + " && T = " + num2str(T(j));
    end
end
legend(legendLabels);