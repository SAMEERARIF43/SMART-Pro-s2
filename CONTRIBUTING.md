# Contributing Guide

This is a solo learning project, but it follows the same conventions used at Codoc so the
workflow transfers directly.

## Branch naming

| Type | Pattern | Example |
|---|---|---|
| Feature | `feat/<short-description>` | `feat/search-bus-by-id` |
| Bug fix | `fix/<short-description>` | `fix/duplicate-stop-print` |
| Docs | `docs/<short-description>` | `docs/update-readme` |
| Chore | `chore/<short-description>` | `chore/add-ci-workflow` |

## Commit messages

- Imperative mood, short subject line: `fix: remove duplicate stop print in RegularMetroBus`
- Prefixes: `feat:`, `fix:`, `docs:`, `chore:`, `refactor:`, `ci:`
- One logical change per commit.

## Workflow

1. Branch off an updated `main`.
2. Commit in small logical steps.
3. Open a pull request, link the issue (`Closes #<number>`).
4. Request review, address feedback.
5. Rebase onto `main` if it has moved.
6. Merge using **Rebase and merge** (project default) unless the task specifically calls for
   squash or a merge commit.

## Local setup

```bash
git clone https://github.com/<username>/smart-metro-bus-system.git
cd smart-metro-bus-system
g++ -std=c++17 -o metro_system.exe main.cpp
```
