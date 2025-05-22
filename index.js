window.addEventListener('scroll', reveal);

function reveal() {
  const elements = document.querySelectorAll('.hero-title, .hero-subtitle, .project-card');
  const windowHeight = window.innerHeight;
  const revealPoint = 150;

  window.addEventListener("scroll", () => {
  const cards = document.querySelectorAll(".project-card");
  cards.forEach(card => {
    const cardTop = card.getBoundingClientRect().top;
    if (cardTop < window.innerHeight - 100) {
      card.classList.add("active");
    }
  });
});

const toggle = document.getElementById("darkModeToggle");
toggle.addEventListener("click", () => {
  document.body.classList.toggle("dark-mode");
  localStorage.setItem("theme", document.body.classList.contains("dark-mode") ? "dark" : "light");
});

window.addEventListener("load", () => {
  if (localStorage.getItem("theme") === "dark") {
    document.body.classList.add("dark-mode");
  }
});

  elements.forEach(el => {
    const elementTop = el.getBoundingClientRect().top;
    if (elementTop < windowHeight - revealPoint) {
      el.classList.add('active');
    }
  });
}

// Run on page load
reveal();
