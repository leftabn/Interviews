package br.com.icarros.testes.angrymarvinbirds;

import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.atomic.AtomicInteger;
import java.util.regex.Pattern;


public class AngryMarvinBirds {

    static List<String> generateCombinations() {
        List<String> results = new ArrayList<>();
        for (int i = 0; i < Math.pow(2, 3); i++) {
            String response = String.format("%3s", Integer.toBinaryString(i))
                    .replaceAll("[ -0]", "-")
                    .replaceAll("1", "*");
            results.add(response);
        }
        return results;
    }

    static int countMarvinStars(List<String> marvinResults) {
        AtomicInteger count = new AtomicInteger(0);
        marvinResults.forEach((e) -> {
            Pattern starRegex = Pattern.compile("\\*");
            count.addAndGet((int) starRegex.matcher(e).results().count());
        });
        return count.get();
    }
    public static void main(String[] args) {
        List<String> combinations = generateCombinations();
        System.out.println(countMarvinStars(combinations));
    }
}
