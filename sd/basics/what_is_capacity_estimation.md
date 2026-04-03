### Summary

[Video](https://www.youtube.com/watch?v=0myM0k1mjZw)

This video walks through an **estimation problem for YouTube’s daily storage and processing needs**, commonly asked in system design interviews. It uses assumptions and back-of-the-envelope calculations to estimate storage, caching, and compute requirements.

---

### Core Concepts and Estimation Breakdown

#### 1. **Estimating Daily Storage of Raw Video Footage**

- **User base:** $10^9$ (1 billion users)
- **Upload ratio:** 1 in 1000 → $10^6$ uploaders/day
- **Average video length:** 10 minutes

- **Video size estimate:**
  - 2-hour movie ≈ 4 GB (high quality)
  - Assumed compressed: 0.4 GB / 2 hours  
  - ⇒ 200 MB/hour ≈ **3 MB/minute**

- **Total raw data per day:**
  $$
  10^7 \text{ minutes} \times 3 \text{ MB/min} = 30 \text{ TB}
  $$

- **With redundancy (3×):**
  $$
  30 \times 3 = 90 \text{ TB}
  $$

- **Multiple resolutions (~2× storage):**
  $$
  90 \times 2 = 180 \text{ TB} \approx 0.2 \text{ PB}
  $$

- **Uncertainty:**
  - If higher quality → up to **~2 PB/day**
  - Depends heavily on assumptions

---

#### 2. **Refined Estimation Using Frames**

- 1 minute = $60 \times 24 = 1440$ frames
- Assume 1 frame ≈ 1 MB

- **Storage per minute:**
  $$
  1440 \text{ MB} \approx 1.5 \text{ GB/min}
  $$

> Shows how different assumptions can drastically change estimates.

---

#### 3. **Caching Metadata**

- **Includes:** thumbnails, titles
- **Thumbnail size (compressed):** ~10 KB

- **Cache scope:** last 90 days

- **Total cache size:**
  $$
  10^9 \times 10 \text{ KB} = 10^9 \text{ KB} = 1 \text{ TB}
  $$

- **Cache infrastructure:**
  - 16 GB RAM per node
  $$
  \frac{1000 \text{ GB}}{16 \text{ GB/node}} \approx 64 \text{ nodes}
  $$

  - With redundancy & scaling → **~500 nodes**

---

#### 4. **Video Processing Requirements**

- **Total video per day:**
  $$
  10^7 \text{ minutes} \approx 1.67 \times 10^5 \text{ hours}
  $$

- **Processing rate:**
  - Seconds/day = 86,400
  $$
  \frac{10^4 \text{ GB}}{86400} \approx 40 \text{ MB/s}
  $$

- **Scaled for real systems:** ~400 MB/s

---

##### Processing Time per MB

| Operation | Time (ms) |
|----------|----------|
| Read     | 10       |
| Process  | 20       |
| Write    | 20       |
| **Total**| **50**   |

- **Compute required:**
  $$
  400 \text{ MB/s} \times 50 \text{ ms} = 20 \text{ sec of work/sec}
  $$

- **Parallelization needed:** ~20 processors

---

### Key Insights

- Always **state and justify assumptions**
- Focus on **order of magnitude**, not exact numbers
- Acceptable error: within **~10×**
- Break problems into:
  - per user → per minute → per second
- Key system factors:
  - **Redundancy**
  - **Caching**
  - **Parallel processing**

---

### Summary Table

| Parameter                         | Estimated Value | Notes |
|----------------------------------|----------------|------|
| Users                            | $10^9$         | Total users |
| Uploaders/day                    | $10^6$         | 1 in 1000 |
| Avg video length                 | 10 min         | Assumed |
| Video size                       | 3 MB/min       | Compressed |
| Raw storage                      | 30 TB          | Per day |
| With redundancy                  | 90 TB          | 3× |
| With resolutions                 | 180 TB (~0.2 PB) | 2× |
| Thumbnail size                   | 10 KB          | Cached |
| Metadata cache                   | 1 TB           | 90 days |
| Cache nodes                      | 64 → 500       | With redundancy |
| Processing rate                  | 40 → 400 MB/s  | Scaled |
| Processing time                  | 50 ms/MB       | Total |
| Processors needed                | ~20            | Parallel |

---

### Conclusion

This approach demonstrates how to:

- Structure estimation problems clearly  
- Break large systems into smaller components  
- Apply realistic system design concepts  
- Prioritize reasoning over precision  

> **Key takeaway:** Strong assumptions + clear reasoning = good system design answer