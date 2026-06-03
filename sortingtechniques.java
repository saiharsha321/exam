import java.util.Arrays;
import java.util.HashMap;
import java.util.LinkedHashMap;
import java.util.Map;
import java.util.stream.Collectors;
public class sortingtechniques {
    public static void main(String[] args) {
        String str = "HelloWelcomeToCN";
        System.out.println("Message: " + str);
        String[] arr = str.split("(?<=\\G.{4})");
        System.out.println("Message divided into frames:");
        Arrays.stream(arr).forEach(System.out::println);
        Map<String, Integer> map = new HashMap<>();
        for (int i = 0; i < arr.length; i++) {
            map.put(arr[i], i);
        }
        System.out.println("\nTransmitted Frames With Sequence Numbers:");
        map.forEach((s, seqNumber) ->
                System.out.println(s + " : " + seqNumber)
        );
        System.out.println("\nFrames after sorting based on Sequence Numbers:");
        Map<String, Integer> sortedMap =
                map.entrySet()
                        .stream()
                        .sorted(Map.Entry.comparingByValue())
                        .collect(Collectors.toMap(
                                Map.Entry::getKey,
                                Map.Entry::getValue,
                                (a, b) -> a,
                                LinkedHashMap::new
                        ));
        sortedMap.forEach((s, seqNumber) ->
                System.out.println(s + " : " + seqNumber)
        );
        System.out.println("\nMessage reconstructed:");
        sortedMap.forEach((s, seqNumber) ->
                System.out.print(s)
        );
    }
}